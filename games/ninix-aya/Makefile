# Created by: UMENO Takashi
# $FreeBSD$

PORTNAME=	ninix-aya
PORTVERSION=	4.4
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_JP}
MASTER_SITE_SUBDIR=	ninix-aya/58500
EXTRACT_SUFX=	.tgz

MAINTAINER=	umeno@rr.iij4u.or.jp
COMMENT=	Ninix-aya is a compatible with desktop mascot program "Ukagaka"

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	png15:${PORTSDIR}/graphics/png
RUN_DEPENDS=	unzip:${PORTSDIR}/archivers/unzip \
		${PYTHON_SITELIBDIR}/chardet/__init__.py:${PORTSDIR}/textproc/py-chardet \
		${PYNUMPY} \
		${PYTHON_SITELIBDIR}/pygst.py:${PORTSDIR}/multimedia/py-gstreamer

USE_PYTHON=	yes
USE_GNOME=	pygtk2
USE_GMAKE=	yes

OPTIONS_DEFINE=	DOCS NLS

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
DOCSDIR=	${PREFIX}/share/doc/ninix
.endif

.if ${PORT_OPTIONS:MNLS}
USES+=	gettext
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
.if ! ${PORT_OPTIONS:MDOCS}
	@${REINPLACE_CMD} -e '/docdir)$$/d' \
		${WRKSRC}/Makefile
.endif
.if ! ${PORT_OPTIONS:MNLS}
	@${REINPLACE_CMD} -e '/localedir/d' \
		${WRKSRC}/Makefile
.endif

.include <bsd.port.mk>
