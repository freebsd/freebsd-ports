# New ports collection makefile for:	opennap
# Date created:			26 July 2000
# Whom:				Donald Burr <dburr@FreeBSD.ORG>
#
# $FreeBSD$
#

PORTNAME=	opennap
PORTVERSION=	0.44
PORTREVISION=	1
CATEGORIES=	audio net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	dburr@FreeBSD.ORG
COMMENT=	The OpenNAP open-source Napster server

USE_GMAKE=	YES
GNU_CONFIGURE=	YES

post-install:
	(${ECHO_CMD} "" ; ${ECHO_CMD} "admin" ; ${ECHO_CMD} "opennap" ; ${ECHO_CMD} "") | ${WRKSRC}/setup
.if defined(NOPORTDOCS)
	@${ECHO_MSG} "===> Documentation skipped."
.else
	@${ECHO_MSG} "===> Installing documentation into ${PREFIX}/share/doc/opennap."
	@${MKDIR} ${PREFIX}/share/doc/opennap
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/opennap
	${INSTALL_DATA} ${WRKSRC}/napster.txt ${PREFIX}/share/doc/opennap
.endif
	@${ECHO_MSG} "===> Installing example config files into ${PREFIX}/share/doc/opennap."
	@${MKDIR} ${PREFIX}/share/opennap/examples
	${CHOWN} -R nobody:nobody ${PREFIX}/share/opennap
	cd ${WRKSRC} ; for FILE in sample.*; do ${INSTALL_DATA} $${FILE} ${PREFIX}/share/opennap/examples ; done
	@${ECHO_MSG} "===> Installing startup script into ${PREFIX}/etc/rc.d."
	${INSTALL_SCRIPT} ${FILESDIR}/opennap.sh ${PREFIX}/etc/rc.d
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
