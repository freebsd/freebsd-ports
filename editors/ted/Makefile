# Ports collection makefile for:  ted
# Date created:			  23 Aug 2001
# Whom:				  Kris Kennaway <kris@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ted
PORTVERSION=	2.14
PORTREVISION=	1
CATEGORIES=	editors textproc print
MASTER_SITES=	ftp://ftp.nluug.nl/pub/editors/ted/
EXTRACT_SUFX=	.src.tar.gz

MAINTAINER=	jon.drews@gmail.com
COMMENT=	X11 based RTF editor

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		tiff.4:${PORTSDIR}/graphics/tiff
RUN_DEPENDS=	${LOCALBASE}/share/ghostscript/fonts/a010013l.pfb:${PORTSDIR}/print/gsfonts

WRKSRC=		${WRKDIR}/Ted-${PORTVERSION}
CONFIGURE_WRKSRC=	${WRKSRC}/Ted

USE_X_PREFIX=	yes
USE_MOTIF=	yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CC="${CC}" CFLAGS="${CFLAGS}"
MAKE_ENV=	DEF_AFMDIR="-DAFMDIR=\"\\\"${AFMDIR}\\\"\"" \
		DEF_INDDIR="-DINDDIR=\"\\\"${INDDIR}\\\"\"" \
		DEF_DOCUMENT_DIR="-DDOCUMENT_DIR=\"\\\"${DOCSDIR}/\\\"\""
ALL_TARGET=	compile.shared

AFMDIR=		${PREFIX}/share/Ted/afm
INDDIR=		${PREFIX}/share/Ted/ind

post-extract:
	cd ${WRKSRC}/tedPackage && ${TAR} xf TedBindist.tar

post-patch:
	${FIND} ${WRKSRC} -name "configure" | ${XARGS} ${REINPLACE_CMD} -e \
		's|/usr/apps|${LOCALBASE}|g ; '
	${REINPLACE_CMD} \
		's|DEF_PKGDIR|DEF_DOCUMENT_DIR|g' ${WRKSRC}/Ted/makefile.in

post-configure:
.for dir in appFrame appUtil bitmap ind libreg
	cd ${WRKSRC}/${dir} && \
		${SETENV} ${CONFIGURE_ENV} ./configure ${CONFIGURE_ARGS}
.endfor

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/Ted/Ted ${PREFIX}/bin
	@${MKDIR} ${AFMDIR}
	${INSTALL_DATA} ${WRKSRC}/tedPackage/afm/* ${AFMDIR}
	@${MKDIR} ${INDDIR}
	${INSTALL_DATA} ${WRKSRC}/tedPackage/ind/US_English.ind ${INDDIR}

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR}  ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/tedPackage/Ted/TedDocument-en_US.rtf ${DOCSDIR}
.endif
.include <bsd.port.mk>
