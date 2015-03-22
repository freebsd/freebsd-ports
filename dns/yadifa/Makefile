# Created by: Mathieu Arnold <mat@FreeBSD.org>
# $FreeBSD$

PORTNAME=	yadifa
PORTVERSION=	2.0.5
DISTVERSIONSUFFIX=	-4735
CATEGORIES=	dns ipv6
MASTER_SITES=	http://cdn.yadifa.eu/sites/default/files/releases/ LOCAL/mat/yadifa

MAINTAINER=	mat@FreeBSD.org
COMMENT=	YADIFA is an authoritative Name Server with DNSSEC capabilities

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING
WITHOUT=TCL DOCS MESSAGES EXAMPLES RRL NSID
OPTIONS_DEFINE=	DOCS EXAMPLES TCL RRL MESSAGES NSID
OPTIONS_DEFAULT=	RRL NSID
OPTIONS_SUB=	yes

RRL_DESC=	Response Rate Limiting
MESSAGES_DESC=	Use messages instead of send (if many ip aliases)
NSID_DESC=	Name Server Identifier Option

GNU_CONFIGURE=	yes
USES=		libtool compiler:c11 tar:tgz
USE_OPENSSL=	yes
CONFIGURE_ARGS=	--localstatedir=/var

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

post-install:
	${INSTALL_DATA} ${WRKSRC}/etc/yadifad.conf.example \
		${STAGEDIR}${PREFIX}/etc/yadifad.conf.sample
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}
	@${MV} ${STAGEDIR}/var/zones ${STAGEDIR}/var/${PORTNAME}

.include <bsd.port.mk>
