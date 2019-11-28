# Created by: Christoph Moench-Tegeder <cmt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	kicad
PORTVERSION=	5.1.5
CATEGORIES=	cad
PKGNAMESUFFIX=	-doc

MAINTAINER=	cmt@FreeBSD.org
COMMENT=	KiCad Documentation and Help Files

LICENSE=	GPLv3+ CC-BY-3.0
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE.adoc

BUILD_DEPENDS=	ja-font-vlgothic>0:japanese/font-vlgothic \
		tex-xetex>0:print/tex-xetex \
		asciidoc:textproc/asciidoc \
		dblatex:textproc/dblatex \
		po4a:textproc/po4a \
		source-highlight:textproc/source-highlight \
		freefont-ttf>0:x11-fonts/freefont-ttf
RUN_DEPENDS=	kicad:cad/kicad

USES=		cmake gettext-tools

USE_GITHUB=	yes
GH_ACCOUNT=	KiCad
GH_PROJECT=	kicad-doc

CONFLICTS=	kicad-devel-r2*

NO_ARCH=	yes

CMAKE_ARGS=	-DLOCALBASE="${LOCALBASE}" \
		-DLANGUAGES="ca;de;en;es;fr;id;it;ja;nl;ru"
INSTALL_TARGET=	install

.include <bsd.port.mk>
