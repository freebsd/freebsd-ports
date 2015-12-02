# Created by: Miguel Mendez <flynn@energyhq.homeip.net>
# $FreeBSD$

PORTNAME=	hercules
PORTVERSION=	3.12
CATEGORIES=	emulators
MASTER_SITES=	http://downloads.hercules-390.eu/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	System/370, ESA/390, and z/Architecture Emulator

LICENSE=	QPL
LICENSE_NAME=	Q PUBLIC LICENSE version 1.0
LICENSE_TEXT=	Please refer to: http://www.hercules-390.org/herclic.html for details
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

# :keepla because port uses lt_dlopen
USES=		iconv libtool:keepla perl5 shebangfix
SHEBANG_FILES=	util/bldlvlck
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-optimization
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e \
		's|SOL_TCP|IPPROTO_TCP|g' ${WRKSRC}/hscutl.c
	@${REINPLACE_CMD} \
		-e '/herclin_LDADD =/s/$$/ libhercu.la libhercd.la/' \
		-e '/hercules_LDADD =/s/$$/ libhercu.la libhercd.la/' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e \
		'/^pkgdatadir/s|=.*|= $$(docdir)|' ${WRKSRC}/html/Makefile.in

.include <bsd.port.mk>
