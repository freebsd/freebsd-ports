# New ports collection makefile for:	REXX/imc
# Version required:			1.6d
# Date created:				Septermber 21 96
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	rexx-imc-1.7
CATEGORIES=	lang
MASTER_SITES=	http://ruby.comlab.ox.ac.uk/imc/distribution/           \
		ftp://ftp.sai.msu.su/pub/unix/rexx/                     \
		ftp://crydee.sai.msu.ru/zeus/unix/rexx/
PATCH_SITES=	${MASTER_SITES}
PATCHFILES=	${DISTNAME}-19990331.patch
PATCH_DIST_STRIP= -p1

MAINTAINER=	jfitz@FreeBSD.org

MAKE_ENV=	MKDIR="${MKDIR}"
MAN1=		rexx.1

.include <bsd.port.pre.mk>

pre-build:
		@ ${CP} ${FILESDIR}/Makefile ${WRKSRC}

post-install:
.if ${PORTOBJFORMAT} == "aout"
	@${ECHO_MSG} "Fixing packing list for a.out"
	@${MV} ${TMPPLIST} ${TMPPLIST}.new
	@${GREP} -v '.so$$' ${TMPPLIST}.new > ${TMPPLIST}
	@${RM} ${TMPPLIST}.new
.endif
	@${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.post.mk>
