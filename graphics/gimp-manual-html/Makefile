# Created by: Brett Taylor
# $FreeBSD$

PORTNAME=	GimpUserManual
PORTVERSION=	2
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://kefk.net/Open_Source/FS/GIMP/Download/GUM/ \
		http://ftp.nluug.nl/ftp/graphics/gimp/manual/
PKGNAMESUFFIX=	-${DOCFORMAT}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	User manual for the GNU Image Manipulation Program (GIMP)

BROKEN=		unfetchable

EXTRACT_ONLY=	#empty
NO_BUILD=	yes
DOCDIR=		${STAGEDIR}${PREFIX}/share/doc/gimp

PLIST=		${PKGDIR}/pkg-plist_${DOCFORMAT}

OPTIONS_SINGLE=	DOCFORMAT
OPTIONS_SINGLE_DOCFORMAT=	HTML PDF
OPTIONS_DEFAULT=	HTML

HTML_DESC=	User manual in HTML format
HTML_DISTFILES=	GimpUsersManual_SecondEdition-HTML_Color.tar.gz \
		GimpUsersManual_SecondEdition-HTML_Search.tar.gz

PDF_DESC=	User manual in PDF format
PDF_DISTFILES=	GimpUsersManual_SecondEdition-PDF_Color.pdf \
		GimpUsersManual_SecondEdition-PDF.pdf

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MHTML}
DOCFORMAT=	HTML
.endif

.if ${PORT_OPTIONS:MPDF}
DOCFORMAT=	PDF
.endif

do-install:
	@${MKDIR} ${DOCDIR}
.for file in ${DISTFILES}
. if ${PORT_OPTIONS:MHTML}
	(cd ${DOCDIR} && ${TAR} -zxf ${DISTDIR}/${file})
. endif
. if ${PORT_OPTIONS:MPDF}
	${INSTALL_DATA} ${DISTDIR}/${file} ${DOCDIR}
. endif
.endfor

.include <bsd.port.mk>
