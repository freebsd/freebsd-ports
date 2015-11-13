# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mmex
PORTVERSION=	1.0.0.0
CATEGORIES=	finance
MASTER_SITES=	SF/moneymanagerex/moneymanagerex/Version%20${PORTVERSION} \
		https://github.com/vslavik/bakefile/releases/download/v0.2.9/:bakefile
DISTFILES=	mmex_${PORTVERSION}_src.tar.bz2 \
		bakefile-0.2.9.tar.gz:bakefile

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Free, open-source, easy-to-use personal finance software

LICENSE=	GPLv2

NO_WRKSUBDIR=	yes

USES=		compiler:c++11-lib gettext gmake tar:bzip2
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-wx-config=${WX_CONFIG}
USE_WX=		3.0
WX_UNICODE=	yes
WX_CONF_ARGS=	absolute
USE_AUTOTOOLS=	aclocal autoconf
ACLOCAL_ARGS=	-I m4 -I bakefile-0.2.9/autoconf \
		--automake-acdir=${ACLOCAL_DIR}
INSTALLS_ICONS=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e \
		's|$$(datadir)/man|$$(prefix)/man|' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e \
		's|\[noext\]|[]|' ${WRKSRC}/configure.ac
	@${REINPLACE_CMD} -e \
		's| -g0 -O2||' ${WRKSRC}/m4/wxpresets.m4

pre-configure:
	@(cd ${WRKSRC} && ${SH} update_revision.sh)

.include <bsd.port.mk>
