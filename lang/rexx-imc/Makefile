# New ports collection makefile for:	REXX/imc
# Version required:			1.6d
# Date created:				Septermber 21 96
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	rexx-imc-1.6d
CATEGORIES=	lang
MASTER_SITES=	http://www.comlab.ox.ac.uk/oucl/users/ian.collier/distribution/

MAINTAINER=	jfitz@FreeBSD.ORG

NO_WRKSUBDIR=	YES

MAKE_ENV=	MKDIR="${MKDIR}"

# we must patch these files until the author correct misuse of 
# errno in struct fileinfo
UGLY_PATCH=	rexx.c rxfn.c util.c

.include <bsd.port.pre.mk>

post-patch:
.for c in ${UGLY_PATCH}
	@${ECHO_MSG} "Changing struct fileinfo member errno to ferrno in ${c}"
	@${MV} ${WRKSRC}/${c} ${WRKSRC}/${c}.old
	@${SED} 's/->errno/->ferrno/g;' ${WRKSRC}/${c}.old > ${WRKSRC}/${c}
	@${RM} ${WRKSRC}/${c}.old
.endfor

pre-build:
		@ ${CP} ${FILESDIR}/Makefile ${WRKDIR}

post-install:
.if ${PORTOBJFORMAT} == "aout"
	@${ECHO_MSG} "Fixing packing list for a.out"
	@${MV} ${TMPPLIST} ${TMPPLIST}.new
	@${GREP} -v '.so$$' ${TMPPLIST}.new > ${TMPPLIST}
	@${RM} ${TMPPLIST}.new
.endif
	@${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.post.mk>
