# $FreeBSD$

PORTNAME=	yadifa
DISTVERSION=	2.3.9
DISTVERSIONSUFFIX=	-8497
CATEGORIES=	dns
MASTER_SITES=	http://cdn.yadifa.eu/sites/default/files/releases/

MAINTAINER=	freebsd@dns.company
COMMENT=	Authoritative nameserver with DNSSEC capabilities

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

USES=	libtool ssl

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=/var

OPTIONS_DEFINE=	CTRL DOCS EXAMPLES TCL RRL MESSAGES NSID
OPTIONS_DEFAULT=	RRL NSID
OPTIONS_SUB=	yes

CTRL_DESC=	Remote control
RRL_DESC=	Response Rate Limiting
MESSAGES_DESC=	Use messages instead of send (if many ip aliases)
NSID_DESC=	Name Server Identifier Option

CTRL_CONFIGURE_ENABLE=	ctrl
TCL_USES=	tcl
TCL_CONFIGURE_ENABLE=	tcl
RRL_CONFIGURE_ENABLE=	rrl
MESSAGES_CONFIGURE_ENABLE=	messages
NSID_CONFIGURE_ENABLE=	nsid

USE_RC_SUBR=	${PORTNAME}d

PORTDOCS=	AUTHORS COPYING ChangeLog \
		INSTALL NEWS README TODO VERSION

post-configure:
	${REINPLACE_CMD} -e 's|^docdir = .*|docdir = ${EXAMPLESDIR}|' ${WRKSRC}/etc/Makefile
	${REINPLACE_CMD} -e 's|/usr/local/var|/var|' -e 's|/var/zones|/var/${PORTNAME}|' ${WRKSRC}/etc/yadifad.conf.example

pre-build:
	cd ${WRKSRC} && ${MAKE_CMD} features

post-install:
	${CP} ${WRKSRC}/etc/yadifad.conf \
		${STAGEDIR}${PREFIX}/etc/yadifad.conf.sample
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}
	${MV} ${STAGEDIR}/var/zones ${STAGEDIR}/var/${PORTNAME}

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/bash_completion.d/
.for f in yadifa yadifad
	${LN} -s ../../${EXAMPLESDIR_REL}/$f.bash_completion \
		${STAGEDIR}${PREFIX}/etc/bash_completion.d/$f.sh
.endfor

.include <bsd.port.mk>
