# Created by: asami
# $FreeBSD$

PORTNAME=	lmbench
PORTVERSION=	3.0.a9
PORTREVISION=	3
PORTEPOCH=	1
CATEGORIES=	benchmarks
MASTER_SITES=	SF/${PORTNAME}/development/${PORTNAME}-3.0-a9 http://thegaul.org/src/
DISTNAME=	${PORTNAME}-${PORTVERSION:C/\.a9/-a9/}

MAINTAINER=	sacchi@gmail.com
COMMENT=	System performance measurement tool

ALL_TARGET=	build
MAKE_ARGS=	CC="${CC}"
MAKE_ENV=	PATH=${PATH}:${WRKSRC}/scripts
USES=		shebangfix perl5 gmake tar:tgz
USE_PERL5=	run
SHEBANG_FILES=	scripts/getresults
PLIST_SUB=	LMBENCH_OS=${ARCH}-${OPSYS:tl}${OSREL}

test: build
	@(cd ${WRKSRC}; make results)

retest: build
	@(cd ${WRKSRC}; make rerun)

# This version seems to think that it's checked out directly from
# bitkeeper.  It wants to look in ../SCCS/s.ChangeSet to find
# its version.  Instead, make ../SCCS/s.ChangeSet old enough that
# make won't care, and create a bk.ver file with the distname in it.
post-extract:
	${MKDIR} ${WRKSRC}/SCCS
	${TOUCH} -t 199901010000 ${WRKSRC}/SCCS/s.ChangeSet
	cd ${WRKSRC}/scripts; ./version > ${WRKSRC}/src/bk.ver
	${ECHO} "#!${SH}" > ${WRKSRC}/scripts/os
	${ECHO} "echo ${ARCH}-${OPSYS:tl}${OSREL}" >> ${WRKSRC}/scripts/os

# Clean up turds from building the library.  Some systems just have
# .o, some also end up with .s, so clean up both.
post-build:
	@${RM} ${WRKSRC}/bin/*/*.[os]

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/lmbench
	${CP} ${FILESDIR}/Makefile ${STAGEDIR}${PREFIX}/lib/lmbench
	tar --exclude \*.orig -C ${WRKSRC} -cf - bin scripts results | \
	  tar -C ${STAGEDIR}${PREFIX}/lib/lmbench -xf -
	${INSTALL_MAN} ${WRKSRC}/doc/*.1 ${STAGEDIR}${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/doc/*.3 ${STAGEDIR}${PREFIX}/man/man3
	${INSTALL_MAN} ${WRKSRC}/doc/*.8 ${STAGEDIR}${PREFIX}/man/man8
	${ECHO_CMD}  ${STAGEDIR}${PREFIX}/lib/lmbench/bin/*/[^l]* \
		${STAGEDIR}${PREFIX}/lib/lmbench/bin/*/l[iao]* \
		${STAGEDIR}${PREFIX}/lib/lmbench/bin/*/lmdd \
		${STAGEDIR}${PREFIX}/lib/lmbench/bin/*/lmhttp \
		| ${XARGS} ${STRIP_CMD}

.include <bsd.port.mk>
