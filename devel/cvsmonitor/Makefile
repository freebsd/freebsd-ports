# New ports collection makefile for:	cvsmonitor
# Date created:    18 May 2003
# Whom:		   Sergey Skvortsov <skv@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	cvsmonitor
PORTVERSION=	0.6.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION:S/./-/g}

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Monitor activity on a CVS Repository

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Storable.pm:${PORTSDIR}/devel/p5-Storable \
		${SITE_PERL}/Time/Duration.pm:${PORTSDIR}/devel/p5-Time-Duration \
		${SITE_PERL}/Class/Autouse.pm:${PORTSDIR}/devel/p5-Class-Autouse \
		${SITE_PERL}/Class/Default.pm:${PORTSDIR}/devel/p5-Class-Default \
		${SITE_PERL}/Class/Inspector.pm:${PORTSDIR}/devel/p5-Class-Inspector \
		${SITE_PERL}/Sort/Versions.pm:${PORTSDIR}/devel/p5-Sort-Versions \
		${SITE_PERL}/${PERL_ARCH}/Proc/ProcessTable.pm:${PORTSDIR}/devel/p5-Proc-ProcessTable \
		${SITE_PERL}/Net/Telnet.pm:${PORTSDIR}/net/p5-Net-Telnet \
		${SITE_PERL}/HTTP/BrowserDetect.pm:${PORTSDIR}/www/p5-HTTP-BrowserDetect \
		${SITE_PERL}/Validate/Net.pm:${PORTSDIR}/net/p5-Validate-Net \
		${SITE_PERL}/Getopt/Long.pm:${PORTSDIR}/devel/p5-Getopt-Long \
		${SITE_PERL}/Chart/Math/Axis.pm:${PORTSDIR}/math/p5-Chart-Math-Axis \
		${SITE_PERL}/File/Flat.pm:${PORTSDIR}/devel/p5-File-Flat \
		${SITE_PERL}/File/Find/Rule.pm:${PORTSDIR}/devel/p5-File-Find-Rule \
		${SITE_PERL}/Time/ParseDate.pm:${PORTSDIR}/devel/p5-Time-modules \
		${SITE_PERL}/URI/Escape.pm:${PORTSDIR}/net/p5-URI \
		${SITE_PERL}/${PERL_ARCH}/Clone.pm:${PORTSDIR}/devel/p5-Clone \
		${SITE_PERL}/Config/Tiny.pm:${PORTSDIR}/devel/p5-Config-Tiny \
		${SITE_PERL}/Array/Window.pm:${PORTSDIR}/devel/p5-Array-Window \
		${SITE_PERL}/${PERL_ARCH}/List/Util.pm:${PORTSDIR}/lang/p5-Scalar-List-Utils \
		${SITE_PERL}/GD/Graph.pm:${PORTSDIR}/graphics/p5-GD-Graph
RUN_DEPENDS=	${BUILD_DEPENDS}

WRKSRC=		${WRKDIR}/${PORTNAME}

NO_BUILD=	yes

USE_PERL5=	yes

# stolen from cvsweb
.if !exists(${PREFIX}/www) && exists(${PREFIX}/share/apache)
CGIDIR?=	share/apache/cgi-bin
.else
CGIDIR?=	www/cgi-bin
.endif

PLIST_SUB=	CVSMON="${CGIDIR}/cvsmonitor"

DIRS_DATA=	html html/Admin html/Browse html/Error html/Search \
		modules modules/AppLib modules/AppLib/CGI \
		modules/AppLib/HTML modules/AppLib/Interface \
		modules/CVSMonitor modules/CVSMonitor/Graph \
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

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
BUILD_DEPENDS+=	${SITE_PERL}/File/Temp.pm:${PORTSDIR}/devel/p5-File-Temp
.endif

.include <bsd.port.post.mk>
