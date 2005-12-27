# New ports collection makefile for:	codeblocks
# Date created:				November, 15th 2005
# Whom:					Matthias Sund <m.sund@arcor.de>
#
# $FreeBSD$
#

PORTNAME=		codeblocks
PORTVERSION=		1.0r2
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE_EXTENDED}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=		${PORTNAME}-1.0rc2
EXTRACT_SUFX=		.tgz

MAINTAINER=	m.sund@arcor.de
COMMENT=	Open source, cross-platform, free C/C++ IDE

BUILD_DEPENDS=	zip:${PORTSDIR}/archivers/zip
LIB_DEPENDS=	wx_gtk2_xrc-2.6.0:${PORTSDIR}/x11-toolkits/wxgtk26

WRKSRC=		${WRKDIR}/${DISTNAME}/src

USE_GMAKE=	yes
INSTALLS_SHLIB=	yes

USE_REINPLACE=	yes

post-extract:
	@${FIND} -E ${WRKSRC} -type f -iregex \
	".*\.(c|h|cpp|am|in|doxy|cbp|template|xrc|html)" -print0 | \
	${XARGS} -0 ${REINPLACE_CMD} -e 's/[[:cntrl:]]*$$//'
	@for f in `${FIND} -E ${WRKSRC} -type f -name Makefile -print`; \
	do ${CP} $$f $$f.bak && (${CAT} $$f.bak | ${TR} -d "\r" > $$f); done
	@${FIND} -E ${WRKSRC} -type f -iregex ".*\.txt" -print0 | \
	${XARGS} -0 ${REINPLACE_CMD} -e 's/[[:cntrl:]]*$$//'
	@(${CAT} ${WRKSRC}/update | ${TR} -d "\r" > ${WRKSRC}/update.sh)

pre-build:
	@${CP} ${FILESDIR}/Makefile ${WRKSRC}

post-build:
	@(${FIND} -E ${WRKSRC} -type f -iregex ".*\.(orig|bak)" -exec ${RM} {} \;)
	@${CHMOD} +x ${WRKSRC}/update.sh
	@(cd ${WRKSRC} && ./update.sh)
	@${MV} ${WRKSRC}/output/share/CodeBlocks ${WRKSRC}/output/share/codeblocks
	@${MV} ${WRKSRC}/output/console_runner.exe ${WRKSRC}/output/console_runner
	@${MV} ${WRKSRC}/output/codeblocks.exe ${WRKSRC}/output/codeblocks

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/output/console_runner ${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/output/${PORTNAME} ${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/output/*.so ${PREFIX}/lib
	@(cd ${WRKSRC}/output && ${FIND} share -type d -exec ${MKDIR} ${PREFIX}/{} \;)
	@(cd ${WRKSRC}/output && ${FIND} share -name "*.so" -type f -exec ${INSTALL_PROGRAM} {} ${PREFIX}/{} \;)
	@(cd ${WRKSRC}/output && ${FIND} share  \! -name "*.so" -type f -exec ${CP} {} ${PREFIX}/{} \;)

post-install:
	@${ECHO} bin/${PORTNAME} >> ${TMPPLIST}
	@${ECHO} bin/console_runner >> ${TMPPLIST}
	@${ECHO} lib/libcodeblocks.so >> ${TMPPLIST}
	@${ECHO} lib/libwxscintilla.so >> ${TMPPLIST}
	@(cd ${WRKSRC}/output && ${FIND} share -type f -exec ${ECHO} {} >> ${TMPPLIST} \;)
	@${ECHO} @dirrm share/${PORTNAME}/images/codecompletion >> ${TMPPLIST}
	@${ECHO} @dirrm share/${PORTNAME}/images >> ${TMPPLIST}
	@${ECHO} @dirrm share/${PORTNAME}/lexers >> ${TMPPLIST}
	@${ECHO} @dirrm share/${PORTNAME}/plugins >> ${TMPPLIST}
	@${ECHO} @dirrm share/${PORTNAME}/templates >> ${TMPPLIST}
	@${ECHO} @dirrm share/${PORTNAME} >> ${TMPPLIST}

.include <bsd.port.mk>
