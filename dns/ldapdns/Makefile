# Created by: Paul Dlug <paul@aps.org>
# $FreeBSD$

PORTNAME=	ldapdns
PORTVERSION=	2.07
PORTREVISION=	2
CATEGORIES=	dns
MASTER_SITES=	https://BSDforge.com/projects/source/dns/ldapdns/

MAINTAINER=	portmaster@bsdforge.com
COMMENT=	LDAP-backed DNS server

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	setuidgid:sysutils/daemontools \
		tcpserver:sysutils/ucspi-tcp

USES=		localbase:ldflags shebangfix tar:xz
USE_OPENLDAP=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX}
USE_CSTD=	gnu89
SHEBANG_FILES=	admin/*

ALL_TARGET=	default

PROGRAMS=	ldapdns ldapaxfr
SCRIPTS=	ldapdns-conf ldapaxfr-conf domainname.sh
PORTDOCS=	AUTHORS CHANGELOG FAQ INSTALL README README.[a-s]*

OPTIONS_DEFINE=	DOCS EXAMPLES

do-install:
	${INSTALL_PROGRAM} ${PROGRAMS:S,^,${WRKSRC}/,} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${SCRIPTS:S,^,${WRKSRC}/,} ${STAGEDIR}${PREFIX}/bin

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/admin
	${INSTALL_DATA} ${WRKSRC}/sample/* ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/admin/* ${STAGEDIR}${EXAMPLESDIR}/admin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
