# New ports collection makefile for:    ez-ipupdate
# Date created:         24 July 2002
# Whom:                 se
#
# $FreeBSD$
#

PORTNAME=	ez-ipupdate
PORTVERSION=	3.0.11b8
PORTREVISION=	1
CATEGORIES=	dns
MASTER_SITES=	http://www.gusnet.cx:8080/proj/ez-ipupdate/dist/

MAINTAINER=	se@FreeBSD.org
COMMENT=	Update your host name on any dynamic DNS service

USE_RC_SUBR=	yes
GNU_CONFIGURE=	yes

post-build:
	@${SED} -e 's,%%PREFIX%%,${PREFIX},g' \
		-e 's,%%RC_SUBR%%,${RC_SUBR},g' \
		${FILESDIR}/${PORTNAME}.sh >${WRKDIR}/${PORTNAME}.sh

post-install:
	${MKDIR} ${PREFIX}/share/examples/${PORTNAME}
	for f in ${WRKSRC}/example-*.conf; \
	do \
		${INSTALL_DATA} $$f ${PREFIX}/share/examples/${PORTNAME}/; \
	done
	${INSTALL_DATA} ${WRKSRC}/example.conf \
			${PREFIX}/etc/${PORTNAME}.conf.sample
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}.sh ${PREFIX}/etc/rc.d/

.include <bsd.port.mk>
