PORTNAME=	geda
PORTVERSION=	1.8.2
DISTVERSIONPREFIX=gaf-
PORTREVISION=	6
PORTEPOCH=	1
CATEGORIES=	cad
MASTER_SITES=	http://ftp.geda-project.org/${PORTNAME}-gaf/stable/v${PORTVERSION:R}/${PORTVERSION}/

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	GPL Electronic Design Automation tools

LICENSE=	GPLv2+

.if ${/usr/bin/ld:L:tA} == /usr/bin/ld.lld
BROKEN=		ld: error: ../src/.libs/libgeda.so: undefined reference to g_input_stream_get_type
.endif

LIB_DEPENDS=	libstroke.so:devel/libstroke \
		libguile.so:lang/guile1
RUN_DEPENDS=	gawk:lang/gawk\

USES=		desktop-file-utils gettext gmake gnome libtool pathfix perl5 \
		pkgconfig python:run shared-mime-info shebangfix
SHEBANG_FILES=	examples/lightning_detector/bom libgeda/docs/*.dox \
		utils/gxyrs/*.pl utils/scripts/* \
		utils/docs/*.dox gattrib/docs/*.dox \
		gschem/docs/*.dox gsymcheck/docs/*.dox \
		gnetlist/docs/*.dox
USE_GNOME=	gtk20
USE_PERL5=	run
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-libstroke=${LOCALBASE}
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}-gaf
DATADIR=	${PREFIX}/share/gEDA
INFO=		geda-scheme
BINARY_WRAPPERS=	gm4

CONFLICTS=	geda-docs geda-examples geda-gattrib \
		geda-gschem geda-netlist geda-symbols \
		geda-symcheck geda-utils libgeda

PORTSCOUT=	limitw:1,even

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
