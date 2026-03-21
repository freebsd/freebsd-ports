PORTNAME=	kicad
DISTVERSION=	10.0.0
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
		asciidoctor-pdf:textproc/rubygem-asciidoctor-pdf \
		po4a:textproc/po4a \
		source-highlight:textproc/source-highlight \
		freefont-ttf>0:x11-fonts/freefont-ttf
RUN_DEPENDS=	kicad:cad/kicad

USES=		cmake gettext-tools

# dependency ordering problems, and also msgmerge already uses
# internal threading
MAKE_JOBS_UNSAFE=	yes

USE_GITLAB=	yes
GL_ACCOUNT=	kicad/services
GL_PROJECT=	kicad-doc

CONFLICTS=	kicad-devel-r2*

NO_ARCH=	yes

# MAKE_ENV+=	LC_CTYPE="en_US.UTF-8" LANG="en_US.UTF-8"
# the PDF build only works with asciidoctor-web-pdf, which is not easy to port
CMAKE_ARGS=	-DLOCALBASE="${LOCALBASE}" \
		-DADOC_TOOLCHAIN=ASCIIDOC \
		-DLANGUAGES="ca;de;en;es;fr;id;it;ja;nl;pl;ru;zh" \
		-DBUILD_FORMATS=html
INSTALL_TARGET=	install

.include <bsd.port.mk>
