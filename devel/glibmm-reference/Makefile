# $FreeBSD$

PATCH_DEPENDS=	${NONEXISTENT}:${.CURDIR}/../glibmm:patch
BUILD_DEPENDS=	${NONEXISTENT}:${.CURDIR}/../glibmm:configure

PARENT_WRKSRC!=	cd ${.CURDIR}/../glibmm && ${MAKE} -V WRKSRC
EXTRACT_ONLY=
USE_GMAKE=	yes

DOCSDIR=	${PREFIX}/share/doc/glibmm-2.4

post-patch:
	@${FIND} ${PARENT_WRKSRC}/examples -name Makefile.in \
		| ${XARGS} ${REINPLACE_CMD} -e '/^install-am:/ s| all-am||'

post-build:
	@${TOUCH} ${PARENT_WRKSRC}/docs/reference/html/index.html

do-install:
.for d in docs examples
	@cd ${PARENT_WRKSRC}/${d} && ${GMAKE} install
.endfor

.include "${.CURDIR}/../../devel/glib20-reference/bsd.gnome-reference.mk"
