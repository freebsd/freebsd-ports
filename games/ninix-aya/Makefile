# New ports collection makefile for:	ninix-aya
# Date created:				6 Dec 2003
# Whom:					UMENO Takashi
#
# $FreeBSD$
#

PORTNAME=	ninix-aya
PORTVERSION=	4.3.7
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_JP}
MASTER_SITE_SUBDIR=	ninix-aya/54300
EXTRACT_SUFX=	.tgz

MAINTAINER=	umeno@rr.iij4u.or.jp
COMMENT=	Ninix-aya is a compatible with desktop mascot program "Ukagaka"

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	png:${PORTSDIR}/graphics/png
RUN_DEPENDS=	unzip:${PORTSDIR}/archivers/unzip \
		${PYTHON_SITELIBDIR}/chardet/__init__.py:${PORTSDIR}/textproc/py-chardet \
		${PYNUMPY} \
		${PYTHON_SITELIBDIR}/pygst.py:${PORTSDIR}/multimedia/py-gstreamer

USE_PYTHON=	yes
USE_GNOME=	pygtk2
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
