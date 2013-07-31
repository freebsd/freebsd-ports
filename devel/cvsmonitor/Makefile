# Created by: Sergey Skvortsov <skv@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cvsmonitor
PORTVERSION=	0.6.3
PORTREVISION=	7
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION}%20Stable
DISTNAME=	${PORTNAME}-${PORTVERSION:S/./-/g}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Monitor activity on a CVS Repository

BUILD_DEPENDS=	p5-Time-Duration>=0:${PORTSDIR}/devel/p5-Time-Duration \
		p5-Class-Autouse>=0:${PORTSDIR}/devel/p5-Class-Autouse \
		p5-Class-Default>=0:${PORTSDIR}/devel/p5-Class-Default \
		p5-Class-Inspector>=0:${PORTSDIR}/devel/p5-Class-Inspector \
		p5-Class-Handle>=0:${PORTSDIR}/devel/p5-Class-Handle \
		p5-Sort-Versions>=0:${PORTSDIR}/devel/p5-Sort-Versions \
		p5-Proc-ProcessTable>=0:${PORTSDIR}/devel/p5-Proc-ProcessTable \
		p5-Net-Telnet>=0:${PORTSDIR}/net/p5-Net-Telnet \
		p5-HTTP-BrowserDetect>=0:${PORTSDIR}/www/p5-HTTP-BrowserDetect \
		p5-Validate-Net>=0:${PORTSDIR}/net/p5-Validate-Net \
		p5-Chart-Math-Axis>=0:${PORTSDIR}/math/p5-Chart-Math-Axis \
		p5-File-NCopy>=0:${PORTSDIR}/devel/p5-File-NCopy \
		p5-File-Remove>=0:${PORTSDIR}/devel/p5-File-Remove \
		p5-File-Flat>=0:${PORTSDIR}/devel/p5-File-Flat \
		p5-File-Find-Rule>=0:${PORTSDIR}/devel/p5-File-Find-Rule \
		p5-File-Which>=0:${PORTSDIR}/sysutils/p5-File-Which \
		p5-TimeDate>=0:${PORTSDIR}/devel/p5-TimeDate \
		p5-Time-modules>=0:${PORTSDIR}/devel/p5-Time-modules \
		p5-URI>=0:${PORTSDIR}/net/p5-URI \
		p5-Clone>=0:${PORTSDIR}/devel/p5-Clone \
		p5-Config-Tiny>=0:${PORTSDIR}/devel/p5-Config-Tiny \
		p5-Array-Window>=0:${PORTSDIR}/devel/p5-Array-Window \
		p5-Number-Compare>=0:${PORTSDIR}/math/p5-Number-Compare \
		p5-Text-Glob>=0:${PORTSDIR}/textproc/p5-Text-Glob \
		p5-XML-Generator>=0:${PORTSDIR}/textproc/p5-XML-Generator \
		p5-GD-Graph>=0:${PORTSDIR}/graphics/p5-GD-Graph
RUN_DEPENDS:=	${BUILD_DEPENDS}

WRKSRC=		${WRKDIR}/${PORTNAME}

NO_BUILD=	yes

USES=		perl5
USE_PERL5=	patch run build

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
	${MKDIR} ${PREFIX}/${CGIDIR}
.for d in ${DIRS_DATA}
	${MKDIR} ${CVSMONITOR_ROOT}/${d}
	${INSTALL_DATA} ${WRKSRC}/${d}/*.* ${CVSMONITOR_ROOT}/${d}
.endfor
.for f in ${FILES_SCRIPT}
	${INSTALL_SCRIPT} ${WRKSRC}/${f} ${CVSMONITOR_ROOT}
.endfor
.for f in ${FILES_DATA}
	${INSTALL_DATA} ${WRKSRC}/${f} ${CVSMONITOR_ROOT}
.endfor
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
