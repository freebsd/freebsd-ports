# Created by: Paul Dlug <paul@aps.org>
# $FreeBSD$

PORTNAME=	ldapdns
PORTVERSION=	2.06
PORTREVISION=	2
CATEGORIES=	dns
MASTER_SITES=	http://bsdforge.com/projects/source/dns/ldapdns/

MAINTAINER=	portmaster@bsdforge.com
COMMENT=	LDAP-backed DNS server

LICENSE=	GPLv2

RUN_DEPENDS=	setuidgid:${PORTSDIR}/sysutils/daemontools \
		tcpserver:${PORTSDIR}/sysutils/ucspi-tcp

OPTIONS_DEFINE=	DOCS EXAMPLES

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

.include <bsd.port.options.mk>

do-install:
.for i in ${PROGRAMS}
	${INSTALL_PROGRAM} ${WRKSRC}/${i} ${STAGEDIR}${PREFIX}/bin
.endfor
.for i in ${SCRIPTS}
	${INSTALL_SCRIPT} ${WRKSRC}/${i} ${STAGEDIR}${PREFIX}/bin
.endfor
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/admin
	${INSTALL_DATA} ${WRKSRC}/sample/* ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/admin/* ${STAGEDIR}${EXAMPLESDIR}/admin
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
