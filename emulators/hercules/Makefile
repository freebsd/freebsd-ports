# Created by: Miguel Mendez <flynn@energyhq.homeip.net>
# $FreeBSD$

PORTNAME=	hercules
PORTVERSION=	3.10
PORTREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	http://downloads.hercules-390.eu/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	System/370, ESA/390, and z/Architecture Emulator

# :keepla because port uses lt_dlopen
USES=		iconv libtool:keepla perl5 shebangfix
SHEBANG_FILES=	util/bldlvlck
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-optimization

OPTIONS_DEFINE=		DOCS

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e \
		's|SOL_TCP|IPPROTO_TCP|g' ${WRKSRC}/hscutl.c
	@${REINPLACE_CMD} -e \
		'/^pkgdatadir/s|=.*|= $$(docdir)|' ${WRKSRC}/html/Makefile.in

.include <bsd.port.mk>
