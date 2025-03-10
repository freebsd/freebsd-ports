PORTNAME=	yadifa
DISTVERSION=	2.6.7
DISTVERSIONSUFFIX=	-11259
CATEGORIES=	dns
MASTER_SITES=	https://www.yadifa.eu/sites/default/files/releases/ \
		https://dns.company/downloads/yadifa/

MAINTAINER=	freebsd@dns.company
COMMENT=	Authoritative nameserver with DNSSEC capabilities
WWW=		https://www.yadifa.eu/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		compiler:c11 cpe libtool ssl
USE_RC_SUBR=	${PORTNAME}d

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=/var

SUB_LIST+=	GROUPS="${GROUPS}" \
		USERS="${USERS}"

USERS=		yadifa
GROUPS=		yadifa

PLIST_SUB=	GROUPS="${GROUPS}" \
		USERS="${USERS}"

PORTDOCS=	AUTHORS COPYING ChangeLog INSTALL NEWS README VERSION

OPTIONS_DEFINE=		CTRL DDNS DNSSECTOOLS DOCS ECDSA EXAMPLES KEYGEN \
			LARGEFILE MASTER NSID RRL RRSIG TCL ZONESIGN
OPTIONS_DEFAULT=	DDNS DNSSECTOOLS DOCS ECDSA EXAMPLES KEYGEN LARGEFILE \
			MASTER NSID RRL RRSIG ZONESIGN
OPTIONS_SUB=		yes

CTRL_DESC=		Remote control
DDNS_DESC=		Dynamic DNS support (DDNS)
DNSSECTOOLS_DESC=	DNSSEC module
ECDSA_DESC=		Elliptic Curve (ECDSA)
KEYGEN_DESC=		Keygen tool
LARGEFILE_DESC=		Support for largefiles
MASTER_DESC=		Use as primary nameserver
NSID_DESC=		Name Server Identifier Option
RRL_DESC=		Response Rate Limiting
RRSIG_DESC=		RRSIG management
ZONESIGN_DESC=		Zonesign tool

CTRL_IMPLIES=			MASTER
CTRL_CONFIGURE_ENABLE=		ctrl
DDNS_CONFIGURE_ENABLE=		dynupdate
DNSSECTOOLS_CONFIGURE_ENABLE=	dnssec-tools
ECDSA_CONFIGURE_ENABLE=		ecdsa
KEYGEN_CONFIGURE_ENABLE=	keygen
LARGEFILE_CONFIGURE_ENABLE=	largefile
MASTER_IMPLIES=			DDNS RRSIG
MASTER_CONFIGURE_ENABLE=	master
NSID_CONFIGURE_ENABLE=		nsid
RRL_CONFIGURE_ENABLE=		rrl
RRSIG_CONFIGURE_ENABLE=		rrsig-management
TCL_USES=			tcl
ZONESIGN_CONFIGURE_ENABLE=	zonesign

post-configure:
	${REINPLACE_CMD} -e 's|^docdir = .*|docdir = ${EXAMPLESDIR}|' ${WRKSRC}/etc/Makefile
	${REINPLACE_CMD} -e 's|/usr/local/var|/var|' -e 's|/var/zones|/var/${PORTNAME}|' ${WRKSRC}/etc/yadifad.conf.example

pre-build:
	cd ${WRKSRC} && ${MAKE_CMD} features

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

post-install:
	${INSTALL_DATA} ${WRKSRC}/etc/yadifad.conf \
		${STAGEDIR}${PREFIX}/etc/yadifad.conf.sample
	${MV} ${STAGEDIR}/var/zones ${STAGEDIR}/var/${PORTNAME}

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/bash_completion.d/
.for f in yadifa yadifad
	${LN} -s ../../${EXAMPLESDIR_REL}/$f.bash_completion \
		${STAGEDIR}${PREFIX}/etc/bash_completion.d/$f.sh
.endfor

.include <bsd.port.mk>
