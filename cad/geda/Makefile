PORTNAME=	geda
PORTVERSION=	1.8.2
DISTVERSIONPREFIX=gaf-
PORTREVISION=	9
PORTEPOCH=	1
CATEGORIES=	cad
MASTER_SITES=	http://ftp.geda-project.org/${PORTNAME}-gaf/stable/v${PORTVERSION:R}/${PORTVERSION}/

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	GPL Electronic Design Automation tools
WWW=		http://www.gpleda.org/

LICENSE=	GPLv2+

LIB_DEPENDS=	libstroke.so:devel/libstroke
RUN_DEPENDS=	gawk:lang/gawk

USES=		desktop-file-utils gettext gmake gnome guile:1.8 libtool \
		perl5 pkgconfig python:run shared-mime-info \
		shebangfix
SHEBANG_FILES=	examples/lightning_detector/bom libgeda/docs/*.dox \
		utils/gxyrs/*.pl utils/scripts/* \
		utils/docs/*.dox gattrib/docs/*.dox \
		gschem/docs/*.dox gsymcheck/docs/*.dox \
		gnetlist/docs/*.dox
USE_GNOME=	gtk20
USE_PERL5=	run
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-libstroke=${LOCALBASE}
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes
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
