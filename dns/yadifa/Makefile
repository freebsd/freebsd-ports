PORTNAME=	yadifa
DISTVERSION=	2.5.3
DISTVERSIONSUFFIX=	-10333
CATEGORIES=	dns
MASTER_SITES=	https://www.yadifa.eu/sites/default/files/releases/ \
		https://dns.company/downloads/yadifa/

MAINTAINER=	freebsd@dns.company
COMMENT=	Authoritative nameserver with DNSSEC capabilities

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

CTRL_CONFIGURE_OFF=		--disable-ctrl
DDNS_CONFIGURE_OFF=		--disable-dynupdate
DNSSECTOOLS_CONFIGURE_OFF=	--disable-dnssec-tools
ECDSA_CONFIGURE_OFF=		--disable-ecdsa
KEYGEN_CONFIGURE_ENABLE=	keygen
LARGEFILE_CONFIGURE_OFF=	--disable-largefile
MASTER_CONFIGURE_OFF=		--disable-master
NSID_CONFIGURE_OFF=		--disable-nsid
RRL_CONFIGURE_OFF=		--disable-rrl
RRSIG_CONFIGURE_OFF=		--disable-rrsig-management
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
