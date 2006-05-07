# Ports collection makefile for:  ted
# Date created:			  23 Aug 2001
# Whom:				  Kris Kennaway <kris@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ted
PORTVERSION=	2.17
CATEGORIES=	editors
MASTER_SITES=	ftp://ftp.nluug.nl/pub/editors/ted/
EXTRACT_SUFX=	.src.tar.gz

MAINTAINER=	ports@freebsd.org
COMMENT=	X11 based RTF editor

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png \
		tiff.4:${PORTSDIR}/graphics/tiff
RUN_DEPENDS=	${LOCALBASE}/share/ghostscript/fonts/a010013l.pfb:${PORTSDIR}/print/gsfonts

WRKSRC=		${WRKDIR}/Ted-${PORTVERSION}

USE_X_PREFIX=	yes
USE_MOTIF=	yes
USE_GHOSTSCRIPT_RUN=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
MAKE_ENV+=	DEF_AFMDIR="-DAFMDIR=\"\\\"${AFMDIR}\\\"\"" \
		DEF_INDDIR="-DINDDIR=\"\\\"${INDDIR}\\\"\"" \
		DEF_DOCUMENT_DIR="-DDOCUMENT_DIR=\"\\\"${DOCSDIR}/\\\"\""
ALL_TARGET=	compile.shared

AFMDIR=		${PREFIX}/share/Ted/afm
INDDIR=		${PREFIX}/share/Ted/ind

post-extract:
	cd ${WRKSRC}/tedPackage && ${TAR} xf TedBindist.tar

post-patch:
	${CP} -p ${FILESDIR}/configure ${WRKSRC}/configure
	${CHMOD} +x ${WRKSRC}/configure
	${REINPLACE_CMD} \
		's|DEF_PKGDIR|DEF_DOCUMENT_DIR|g' ${WRKSRC}/Ted/makefile.in

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/Ted/Ted ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/tedPackage/Ted/rtf2*.sh ${PREFIX}/bin/
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
