# Created by: Paul Dlug <paul@aps.org>
# $FreeBSD$

PORTNAME=	ldapdns
PORTVERSION=	2.06
PORTREVISION=	2
CATEGORIES=	dns
MASTER_SITES=	http://www.nimh.org/dl/

MAINTAINER=	sylvio@FreeBSD.org
COMMENT=	LDAP-backed DNS server

RUN_DEPENDS=	setuidgid:${PORTSDIR}/sysutils/daemontools \
		tcpserver:${PORTSDIR}/sysutils/ucspi-tcp

LICENSE=	GPLv2

USE_OPENLDAP=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX}
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
USE_CSTD=	gnu89

ALL_TARGET=	default

PROGRAMS=	ldapdns ldapaxfr
SCRIPTS=	ldapdns-conf ldapaxfr-conf domainname.sh
DOCS=		AUTHORS CHANGELOG FAQ INSTALL README README.[a-s]*

do-install:
.for i in ${PROGRAMS}
	${INSTALL_PROGRAM} ${WRKSRC}/${i} ${PREFIX}/bin
.endfor
.for i in ${SCRIPTS}
	${INSTALL_SCRIPT} ${WRKSRC}/${i} ${PREFIX}/bin
.endfor
	@${MKDIR} ${EXAMPLESDIR}/admin
	${INSTALL_DATA} ${WRKSRC}/sample/* ${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/admin/* ${EXAMPLESDIR}/admin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
