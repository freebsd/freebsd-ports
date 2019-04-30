# Created by: Andreas Klemm <andreas@klemm.gtn.com>
# $FreeBSD$

PORTNAME=	star
DISTVERSION=	1.6
CATEGORIES=	archivers
MASTER_SITES=	SF/s-tar

MAINTAINER=	mm@FreeBSD.org
COMMENT=	Unique standard tape archiver with many enhancements

LICENSE=	CDDL GPLv2
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/CDDL.Schily.txt

BUILD_DEPENDS=	gm4:devel/m4

USES=		gmake gettext iconv tar:bzip2

MAKE_ARGS=	GMAKE_NOWARN=true DESTDIR=${STAGEDIR} INS_BASE=${PREFIX} \
		MANBASE=

PORTDOCS=	README README.crash README.mtio README.pattern STARvsGNUTAR \
		README.ACL README.largefiles README.otherbugs \
		README.posix-2001

OPTIONS_DEFINE=	DOCS

post-patch:
	@${FIND} ${WRKSRC} -type f -print \
		| ${XARGS} ${REINPLACE_CMD} -e "s@/etc/default@${PREFIX}/etc@g"
	@${MV} ${WRKSRC}/rmt/rmt.1 ${WRKSRC}/rmt/srmt.1

post-stage:
	@${RM} ${STAGEDIR}/${PREFIX}/bin/mt \
	       ${STAGEDIR}/${PREFIX}/include/schily/*.h \
	       ${STAGEDIR}/${PREFIX}/include/schily/*/*.h \
	       ${STAGEDIR}/${PREFIX}/lib/*.a \
	       ${STAGEDIR}/${PREFIX}/lib/profiled/*.a \
	       ${STAGEDIR}/${PREFIX}/man/man1/match.1* \
	       ${STAGEDIR}/${PREFIX}/man/man1/mt.1* \
	       ${STAGEDIR}/${PREFIX}/man/man3/*.3* \
	       ${STAGEDIR}/${PREFIX}/man/man5/makerules.5* \
	       ${STAGEDIR}/${PREFIX}/man/man5/makefiles.5*
	@${RMDIR} ${STAGEDIR}/${PREFIX}/include/schily/* \
		  ${STAGEDIR}/${PREFIX}/include/schily \
		  ${STAGEDIR}/${PREFIX}/lib/profiled

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for FILE in ${PORTDOCS}
	(cd ${WRKSRC}/star && ${INSTALL_DATA} ${FILE} ${STAGEDIR}${DOCSDIR}/${FILE})
.endfor

.include <bsd.port.mk>
