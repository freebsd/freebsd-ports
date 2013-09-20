# Created by: Jean-Yves Lefort <jylefort@FreeBSD.org>
# $FreeBSD$

PORTREVISION=	1

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/glibmm-2.4.pc:${PORTSDIR}/devel/glibmm \
		gm4:${PORTSDIR}/devel/m4

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USES=		pkgconfig

DOCSDIR=	${PREFIX}/share/doc/glibmm-2.4

NO_STAGE=	yes
post-patch:
	@${FIND} ${WRKSRC}/examples -name Makefile.in \
		| ${XARGS} ${REINPLACE_CMD} -e '/^install-am:/ s| all-am||'

post-build:
	@${TOUCH} ${WRKSRC}/docs/reference/html/index.html

do-install:
.  for d in docs examples
	@cd ${WRKSRC}/${d} && ${GMAKE} install
.  endfor


.include "${.CURDIR}/../../devel/glib20-reference/bsd.gnome-reference.mk"
