# New ports collection makefile for:	ldapdns
# Date created:		2004-01-06
# Whom:			Paul Dlug <paul@aps.org>
#
# $FreeBSD$
#

PORTNAME=	ldapdns
PORTVERSION=	2.05
CATEGORIES=	dns
MASTER_SITES=	http://www.nimh.org/dl/

MAINTAINER=	paul@aps.org
COMMENT=	LDAP-backed DNS server

RUN_DEPENDS=	setuidgid:${PORTSDIR}/sysutils/daemontools \
		tcpserver:${PORTSDIR}/sysutils/ucspi-tcp

USE_OPENLDAP=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ENV=	CFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--prefix=${PREFIX}
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

ALL_TARGET=	default

PROGRAMS=	ldapdns ldapaxfr
SCRIPTS=	ldapdns-conf ldapaxfr-conf domainname.sh
DOCS=		AUTHORS CHANGELOG FAQ INSTALL README README.[a-s]*

do-install:
	cd ${WRKSRC} && \
	${INSTALL_PROGRAM} ${PROGRAMS} ${PREFIX}/bin && \
	${INSTALL_SCRIPT} ${SCRIPTS} ${PREFIX}/bin
	@${MKDIR} ${EXAMPLESDIR}/admin
	${INSTALL_DATA} ${WRKSRC}/sample/* ${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/admin/* ${EXAMPLESDIR}/admin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
