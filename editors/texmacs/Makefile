# Created by: Geoffrey Mainland <mainland@apeiron.net>
# $FreeBSD$

PORTNAME=	texmacs
PORTVERSION=	1.0.7.21
PORTREVISION=	3
CATEGORIES=	editors print
MASTER_SITES=	ftp://ftp.texmacs.org/TeXmacs/tmftp/source/ \
		http://www.predatorlabs.net/dl/
DISTNAME=	TeXmacs-${PORTVERSION}-src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	WYSIWYG scientific text editor

LICENSE=	GPLv3

LIB_DEPENDS=	libguile.so:${PORTSDIR}/lang/guile

USES=		gmake shared-mime-info desktop-file-utils python shebangfix
USE_TEX=	tex
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--enable-optimize="${CXXFLAGS}"
MAKE_ARGS=	CP="${CP} -R -f"
ALL_TARGET=	${PORTNAME:tu}
INSTALL_ICONS=	yes

SHEBANG_FILES=	plugins/asymptote/bin/tm_asy2 \
		plugins/feynmf/bin/bbox_add.pl \
		plugins/asymptote/bin/perl-tm_asy

DATADIR=	${PREFIX}/share/TeXmacs

OPTIONS_DEFINE=	FREETYPE GHOSTSCRIPT ICONV IMLIB2 PDF QT4
OPTIONS_DEFAULT=FREETYPE GHOSTSCRIPT ICONV IMLIB2 QT4
PDF_DESC=	Experimental PDF renderer

FREETYPE_LIB_DEPENDS=	libfreetype.so:${PORTSDIR}/print/freetype2
FREETYPE_CONFIGURE_WITH=freetype=linked

GHOSTSCRIPT_USE=	GHOSTSCRIPT=yes
GHOSTSCRIPT_CONFIGURE_WITH=	gs=yes

ICONV_USES=		iconv
ICONV_CONFIGURE_WITH=	iconv

IMLIB2_USE=		EFL=imlib2
IMLIB2_CONFIGURE_ON=	--with-imlib2
IMLIB2_CONFIGURE_OFF=	--without-imlib

PDF_CONFIGURE_ON=	--enable-pdf-renderer

QT4_USE=		QT4=gui,moc_build,qmake_build,rcc,uic_build
QT4_CONFIGURE_ON=	--with-qt --enable-qtpipes
QT4_CONFIGURE_OFF=	--disable-qt

post-patch:
	@${GREP} -lR "#!/bin/bash" ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} -e \
		 's|#!/bin/bash|#!/bin/sh|g'
	@${FIND} ${WRKSRC} -name \*.bak -delete
	@${FIND} ${WRKSRC} -name \*.DS_Store -delete
	@${REINPLACE_CMD} -e 's|ICONV_LDFLAGS/-liconv|ICONV_LDFLAGS|' \
		${WRKSRC}/configure
	@ #fix for namespace clash with Qt3
	@${REINPLACE_CMD} -e 's|qdrawutil.h|qt4/Qt/qdrawutil.h|' \
		${WRKSRC}/src/Plugins/Qt/QTMStyle.cpp

.include <bsd.port.mk>
