# New ports collection makefile for:	festdoc
# Date created:        			2000-06-16
# Whom:					Trevor Johnson <trevor@jpj.net>
# based on the NetBSD port
#
# $NetBSD: Makefile,v 1.7 2000/01/05 17:56:46 wiz Exp $
# $FreeBSD$
#

PORTNAME=	festdoc
PORTVERSION=	1.4.0.1
CATEGORIES=	audio
MASTER_SITES=	http://www.speech.cs.cmu.edu/festival/cstr/festival/1.4.1/ \
		${MASTER_SITE_NETBSD} \
		ftp://ftp.cstr.ed.ac.uk/pub/festival/1.4.1/
DIST_SUBDIR=	festival

MAINTAINER=	trevor@FreeBSD.org

NO_BUILD=	yes

INFO_FILES=	festival.info
FDOC=		${PREFIX}/share/doc/festival

post-extract:
	${CHMOD} -R a+r ${WRKSRC}
	${FIND} ${WRKSRC} -type d -print0 | xargs -0 ${CHMOD} 755
	${RM} ${WRKSRC}/festival/src-manual/c3750.htm~
	${RM} ${WRKSRC}/speechtools/c16909.htm~
	${RMDIR} ${WRKSRC}/festival/src-manual/images_gen

do-install:
	${MKDIR} ${FDOC}
	${RM} ${WRKSRC}/festival/info/festival.info.orig
	cd ${WRKSRC} && info=`find . -name '*.info*' -type f` && \
	  ${CP} $$info ${PREFIX}/info && \
	  ${CP} -r ${WRKSRC}/* ${FDOC} && \
	  cd ${FDOC} && \
	  ${RM} -f $$info && \
	  ${RMDIR} festival/info

.include <bsd.port.mk>
