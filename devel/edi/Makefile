PORTNAME=	edi
PORTVERSION=	0.8.0
CATEGORIES=	devel enlightenment
MASTER_SITES=	https://github.com/Enlightenment/edi/releases/download/v${PORTVERSION}/ # http://download.enlightenment.org/rel/apps/${PORTNAME}/
DIST_SUBDIR=	enlightenment

MAINTAINER=	enlightenment@FreeBSD.org
COMMENT=	EFL-based/focused IDE
WWW=		https://phab.enlightenment.org/w/projects/edi/

LIB_DEPENDS=	libelementary.so:devel/efl

USES=		desktop-file-utils gettext meson pkgconfig tar:xz
MESON_ARGS=	-Dlibclang=false
USE_LDCONFIG=	yes

PORTDOCS=	AUTHORS NEWS TODO

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e '/input : join_paths/d' \
		${WRKSRC}/data/extra/templates/meson.build
# XXX: should probably use get_option('mandir') below
	@${REINPLACE_CMD} -e '/install_dir/s,doc/edi,man/man1,' \
		${WRKSRC}/doc/meson.build
	@${REINPLACE_CMD} -e '/tests/d' ${WRKSRC}/src/meson.build
	@${ECHO_CMD} "option('docsdir', type : 'string'," \
		"value : '${DOCSDIR_REL}')" >> ${WRKSRC}/meson_options.txt
	@${ECHO_CMD} "option('localbase', type : 'string'," \
		"value : '${LOCALBASE}')" >> ${WRKSRC}/meson_options.txt

.include <bsd.port.mk>
