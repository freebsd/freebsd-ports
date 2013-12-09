# Created by: Jean-Yves Lefort <jylefort@FreeBSD.org>
# $FreeBSD$

PORTREVISION=	1

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/glibmm-2.4.pc:${PORTSDIR}/devel/glibmm \
		gm4:${PORTSDIR}/devel/m4

GNU_CONFIGURE=	yes
USES=		gmake pkgconfig

DOCSDIR=	${PREFIX}/share/doc/glibmm-2.4

post-patch:
	@${FIND} ${WRKSRC}/examples -name Makefile.in \
		| ${XARGS} ${REINPLACE_CMD} -e '/^install-am:/ s| all-am||'

post-build:
	@${TOUCH} ${WRKSRC}/docs/reference/html/index.html

do-install:
.  for d in docs examples
	@cd ${WRKSRC}/${d} && ${GMAKE} ${MAKE_ARGS} install
.  endfor


.include "${.CURDIR}/../../devel/glib20-reference/bsd.gnome-reference.mk"
