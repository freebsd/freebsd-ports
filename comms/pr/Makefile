# Created by: Anton Voronin <anton@urc.ac.ru>
# $FreeBSD$

PORTNAME=	pr
PORTVERSION=	1.1
PORTREVISION=	1
CATEGORIES=	comms net
MASTER_SITES=	https://BSDforge.com/projects/source/comms/pr/

MAINTAINER=	portmaster@bsdforge.com
COMMENT=	Daemon that connects local terminal device to a terminal server

LICENSE=	ARTPERL10

USES=		shebangfix tar:xz
SHEBANG_FILES=	sbin/PortRedirector sbin/PortTest
NO_BUILD=	YES

WRKSRC=		${WRKDIR}/${PORTNAME}
PROGRAMS=	PortRedirector PortTest
ETCFLS=		PortRedirector.conf.sample
RCDFILES=	pr.sh.sample

OPTIONS_DEFINE=	DOCS

do-install:
	(cd ${WRKSRC}/sbin && \
		${INSTALL_SCRIPT} ${PROGRAMS} ${STAGEDIR}${PREFIX}/sbin)
	(cd ${WRKSRC}/etc/rc.d && \
		${INSTALL_DATA} ${RCDFILES} ${STAGEDIR}${PREFIX}/etc/rc.d)
	(cd ${WRKSRC}/etc && \
		${INSTALL_DATA} ${ETCFLS} ${STAGEDIR}${PREFIX}/etc)
do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/share/doc/pr/PR.html ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
