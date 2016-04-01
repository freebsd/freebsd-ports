# Created by: Sergey Skvortsov <skv@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cvsmonitor
DISTVERSION=	0-6-3
PORTREVISION=	8
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION}%20Stable

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Monitor activity on a CVS Repository

BUILD_DEPENDS=	p5-Time-Duration>=0:devel/p5-Time-Duration \
		p5-Class-Autouse>=0:devel/p5-Class-Autouse \
		p5-Class-Default>=0:devel/p5-Class-Default \
		p5-Class-Inspector>=0:devel/p5-Class-Inspector \
		p5-Class-Handle>=0:devel/p5-Class-Handle \
		p5-Sort-Versions>=0:devel/p5-Sort-Versions \
		p5-Proc-ProcessTable>=0:devel/p5-Proc-ProcessTable \
		p5-Net-Telnet>=0:net/p5-Net-Telnet \
		p5-HTTP-BrowserDetect>=0:www/p5-HTTP-BrowserDetect \
		p5-Validate-Net>=0:net/p5-Validate-Net \
		p5-Chart-Math-Axis>=0:math/p5-Chart-Math-Axis \
		p5-File-NCopy>=0:devel/p5-File-NCopy \
		p5-File-Remove>=0:devel/p5-File-Remove \
		p5-File-Flat>=0:devel/p5-File-Flat \
		p5-File-Find-Rule>=0:devel/p5-File-Find-Rule \
		p5-File-Which>=0:sysutils/p5-File-Which \
		p5-TimeDate>=0:devel/p5-TimeDate \
		p5-Time-modules>=0:devel/p5-Time-modules \
		p5-URI>=0:net/p5-URI \
		p5-Clone>=0:devel/p5-Clone \
		p5-Config-Tiny>=0:devel/p5-Config-Tiny \
		p5-Array-Window>=0:devel/p5-Array-Window \
		p5-Number-Compare>=0:math/p5-Number-Compare \
		p5-Text-Glob>=0:textproc/p5-Text-Glob \
		p5-XML-Generator>=0:textproc/p5-XML-Generator \
		p5-GD-Graph>=0:graphics/p5-GD-Graph
RUN_DEPENDS:=	${BUILD_DEPENDS}

WRKSRC=		${WRKDIR}/${PORTNAME}

NO_BUILD=	yes
NO_ARCH=	yes

USES=		perl5 shebangfix
USE_PERL5=	patch run build
SHEBANG_FILES=	*.pl

# stolen from cvsweb
.if !exists(${PREFIX}/www) && exists(${PREFIX}/share/apache)
CGIDIR?=	share/apache/cgi-bin
.else
CGIDIR?=	www/cgi-bin
.endif

PLIST_SUB=	CVSMON="${CGIDIR}/cvsmonitor"

DIRS_DATA=	html html/Admin html/Browse html/Error html/Search \
		modules modules/AppLib modules/AppLib/Interface \
		modules/CVSMonitor modules/CVSMonitor/Graph \
		modules/CVSMonitor/Backend modules/CVSMonitor/HTML \
		modules/CVSMonitor/Range modules/CVSMonitor/MetaData \
		modules/CVSMonitor/MetaData/Abstract setup \
		setup/html static/style static/images
FILES_SCRIPT=	cvsexec.pl cvsmonitor.pl setup.pl
FILES_DATA=	README setup.conf

CVSMONITOR_ROOT=	${PREFIX}/${CGIDIR}/cvsmonitor

post-patch:
	@${PERL} -pi -e '$$_=q{	my $$solaris=1;} if $$.==270' \
		${WRKSRC}/modules/CVSMonitor/MetaData/Module.pm

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${CGIDIR}
.for d in ${DIRS_DATA}
	@${MKDIR} ${STAGEDIR}${CVSMONITOR_ROOT}/${d}
	${INSTALL_DATA} ${WRKSRC}/${d}/*.* ${STAGEDIR}${CVSMONITOR_ROOT}/${d}
.endfor
.for f in ${FILES_SCRIPT}
	${INSTALL_SCRIPT} ${WRKSRC}/${f} ${STAGEDIR}${CVSMONITOR_ROOT}
.endfor
.for f in ${FILES_DATA}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${CVSMONITOR_ROOT}
.endfor

.include <bsd.port.mk>
