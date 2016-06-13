# Created by: lightside <lightside@gmx.com>
# $FreeBSD$

PORTNAME=	pcc-libs
PORTVERSION=	1.1.0
CATEGORIES=	devel
MASTER_SITES=	ftp://pcc.ludd.ltu.se/pub/pcc-releases/ \
		http://pcc.ludd.ltu.se/ftp/pub/pcc-releases/

MAINTAINER=	pi@FreeBSD.org
COMMENT=	Libraries for the Portable C Compiler

LICENSE=	BSDCOMPATIBLE BSD2CLAUSE BSD3CLAUSE
LICENSE_COMB=	multi
LICENSE_NAME_BSDCOMPATIBLE=	BSD-style compatible licenses
LICENSE_TEXT_BSDCOMPATIBLE=	The license: BSDCOMPATIBLE (${LICENSE_NAME_BSDCOMPATIBLE}),\
	please read from the web: http://pcc.ludd.ltu.se/licenses/
LICENSE_PERMS_BSDCOMPATIBLE=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

ONLY_FOR_ARCHS=	i386 amd64

USES=	gmake tar:tgz
GNU_CONFIGURE=	yes

DATADIR=	${PREFIX}/lib/pcc
PORTDATA=	*

.include <bsd.port.pre.mk>

post-patch:
.if ${OPSYS} == FreeBSD
	@${REINPLACE_CMD} -e '/targmach=amd64/s/x86_64/amd64/' \
		${WRKSRC}/configure
.endif

.include <bsd.port.post.mk>
