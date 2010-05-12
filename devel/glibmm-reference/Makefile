# New ports collection makefile for:	glibmm-reference
# Date created:				09 May 2006
# Whom:					Jean-Yves Lefort <jylefort@FreeBSD.org>
#
# $FreeBSD$
#

PORTREVISION=	5

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/glibmm-2.4.pc:${PORTSDIR}/devel/glibmm \
		gm4:${PORTSDIR}/devel/m4

USE_GMAKE=	yes
GNU_CONFIGURE=	yes

DOCSDIR=	${PREFIX}/share/doc/glibmm-2.4

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
