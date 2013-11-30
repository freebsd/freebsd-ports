# Created by: Mathieu Arnold <mat@FreeBSD.org>
# $FreeBSD$

PORTNAME=	yadifa
PORTVERSION=	1.0.3
PORTREVISION=	1
DISTVERSIONSUFFIX=	-2880
CATEGORIES=	dns ipv6
MASTER_SITES=	http://cdn.yadifa.eu/sites/default/files/releases/

MAINTAINER=	mat@FreeBSD.org
COMMENT=	YADIFA is an authoritative Name Server with DNSSEC capabilities

LICENSE=	BSD

OPTIONS_DEFINE=	DOCS EXAMPLES TCL

GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	libtool
USE_OPENSSL=	yes
CONFIGURE_ARGS=	--localstatedir=/var
TCL_USES=	tcl
TCL_CONFIGURE_ENABLE=	tcl

USE_RC_SUBR=	${PORTNAME}d

PORTDOCS=	AUTHORS COPYING ChangeLog \
		INSTALL NEWS README TODO VERSION

post-configure:
	${REINPLACE_CMD} -e 's|^docdir = .*|docdir = ${EXAMPLESDIR}|' ${WRKSRC}/etc/Makefile
	${REINPLACE_CMD} -e 's|/usr/local/var|/var|' -e 's|/var/zones|/var/${PORTNAME}|' ${WRKSRC}/etc/yadifad.conf.example

post-install:
	${INSTALL_DATA} ${WRKSRC}/etc/yadifad.conf.example ${STAGEDIR}${PREFIX}/etc/
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}
	@${MV} ${STAGEDIR}/var/zones ${STAGEDIR}/var/${PORTNAME}

.include <bsd.port.mk>
