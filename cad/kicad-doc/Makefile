PORTNAME=	kicad
DISTVERSION=	9.0.4
CATEGORIES=	cad
PKGNAMESUFFIX=	-doc

MAINTAINER=	cmt@FreeBSD.org
COMMENT=	KiCad Documentation and Help Files
WWW=		https://gitlab.com/kicad/services/kicad-doc

LICENSE=	GPLv3+ CC-BY-3.0
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE.adoc

BUILD_DEPENDS=	ja-font-vlgothic>0:japanese/font-vlgothic \
		asciidoc:textproc/asciidoc \
		tex-xetex>0:print/tex-xetex \
		fop:textproc/fop \
		po4a:textproc/po4a \
		source-highlight:textproc/source-highlight \
		freefont-ttf>0:x11-fonts/freefont-ttf
RUN_DEPENDS=	kicad:cad/kicad

USES=		cmake gettext-tools

USE_GITLAB=	yes
GL_ACCOUNT=	kicad/services
GL_PROJECT=	kicad-doc

CONFLICTS=	kicad-devel-r2*

NO_ARCH=	yes

CMAKE_ARGS=	-DLOCALBASE="${LOCALBASE}" \
		-DLANGUAGES="ca;de;en;es;fr;id;it;ja;nl;pl" \
		-DADOC_TOOLCHAIN=ASCIIDOC \
		-DPDF_GENERATOR=FOP
INSTALL_TARGET=	install

.include <bsd.port.mk>
