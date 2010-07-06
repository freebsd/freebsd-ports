# New ports collection makefile for:	ninix-aya
# Date created:				6 Dec 2003
# Whom:					UMENO Takashi
#
# $FreeBSD$
#

PORTNAME=	ninix-aya
PORTVERSION=	4.0.7
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_JP}
MASTER_SITE_SUBDIR=	ninix-aya/47881
DISTNAME=	ninix-aya-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	umeno@rr.iij4u.or.jp
COMMENT=	Ninix-aya is a compatible with desktop mascot program "Ukagaka"

LIB_DEPENDS=	png:${PORTSDIR}/graphics/png
RUN_DEPENDS=	unzip:${PORTSDIR}/archivers/unzip \
		${PYTHON_SITELIBDIR}/gtk-2.0/gtk/__init__.py:${PORTSDIR}/x11-toolkits/py-gtk2 \
		${PYTHON_SITELIBDIR}/chardet/__init__.py:${PORTSDIR}/textproc/py-chardet \
		${PYTHON_SITELIBDIR}/numpy:${PORTSDIR}/math/py-numpy \
		${PYTHON_SITELIBDIR}/pygst.py:${PORTSDIR}/multimedia/py-gstreamer

PYVERSION=	${PYTHON_VERSION:S/^python//}
.if defined(PYTHON_VERSION) && ${PYVERSION:S/.//} < 24
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/japanese.pth:${PORTSDIR}/japanese/pycodec
.endif # defined(PYVERSION) && ${PYVERSION:S/.//} < 24

USE_PYTHON=	yes
USE_GMAKE=	yes

.include <bsd.port.pre.mk>

.if !defined(NOPORTDOCS)
DOCSDIR=	${PREFIX}/share/doc/ninix
.endif

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
PLIST_SUB+=	NLS="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -E -e 's,\$$\(DESTDIR\)(.*),\1,' \
		-e 's,/opt/ninix-aya,$$(PREFIX),' \
		-e 's,lib/ninix,libexec/ninix,'	\
		-e 's,/doc,/share/doc/ninix,' \
		${WRKSRC}/Makefile
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e '/docdir)$$/d' \
		${WRKSRC}/Makefile
.endif
.if defined(WITHOUT_NLS)
	@${REINPLACE_CMD} -e '/localedir/d' \
		${WRKSRC}/Makefile
.endif

.include <bsd.port.post.mk>
