# New ports collection makefile for:	p7zip
# Date created:			Sun Jul 18 15:07:26 CEST 2004
# Whom:				Juergen Lock <nox@jelal.kn-bremen.de>
#
# $FreeBSD$
#

PORTNAME=	p7zip
PORTVERSION=	0.91
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	p7zip
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	nox@jelal.kn-bremen.de
COMMENT=	Command line versions of 7-zip

USE_BZIP2=	yes
USE_GMAKE=	yes
MAKEFILE=	makefile
ONLY_FOR_ARCHS=	alpha amd64 i386 ia64

USE_REINPLACE=	yes
MMACHINE=	${WRKSRC}/makefile.machine

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500039
BROKEN=		'Requires wchar functions (mbrtowc(3) etc.) for compilation'
.endif

post-patch:
	${ECHO} "LOCAL_LIBS=	${PTHREAD_LIBS}" > ${MMACHINE}
	${ECHO} "LOCAL_FLAGS+=	${PTHREAD_CFLAGS}" >> ${MMACHINE}
	${REINPLACE_CMD} -e 's/-O2/${CXXFLAGS}/' ${WRKSRC}/makefile.glb

do-install:
	${MKDIR} ${PREFIX}/libexec/p7zip/Codecs
	${MKDIR} ${PREFIX}/libexec/p7zip/Formats
	${INSTALL_PROGRAM} ${WRKSRC}/bin/7z ${PREFIX}/libexec/p7zip
	${INSTALL_PROGRAM} ${WRKSRC}/bin/7za ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/bin/Codecs/* ${PREFIX}/libexec/p7zip/Codecs
	${INSTALL_DATA} ${WRKSRC}/bin/Formats/* ${PREFIX}/libexec/p7zip/Formats
	${INSTALL_SCRIPT} ${FILESDIR}/7z ${PREFIX}/bin
	${MKDIR} ${PREFIX}/share/doc/p7zip/commands
	${MKDIR} ${PREFIX}/share/doc/p7zip/switches
	${INSTALL_DATA} ${WRKSRC}/html/cmdline/*.htm ${PREFIX}/share/doc/p7zip
	${INSTALL_DATA} ${WRKSRC}/html/cmdline/commands/* ${PREFIX}/share/doc/p7zip/commands
	${INSTALL_DATA} ${WRKSRC}/html/cmdline/switches/* ${PREFIX}/share/doc/p7zip/switches

.include <bsd.port.post.mk>
