# New ports collection makefile for:    Jed text editor
# Date created:         22 APR 1997
# Whom:                 eric
#
# $FreeBSD$
#

PORTNAME=	jed
PORTVERSION=	0.98.7
CATEGORIES=	editors
MASTER_SITES=	ftp://space.mit.edu/pub/davis/jed/v0.98/
DISTNAME=	${PORTNAME}0.98-7

PATCH_SITES=	ftp://space.mit.edu/pub/davis/jed/v0.98/
PATCHFILES=	BUGS
PATCH_DIST_STRIP=	-p1

MAINTAINER=	eric@cybernut.com

LIB_DEPENDS=	slang.1:${PORTSDIR}/devel/libslang

USE_XLIB=	yes

.if !defined(NO_XJED)
XJED=	xjed
.endif

DIST_SUBDIR=	jed
GNU_CONFIGURE=	yes
PATCH_DIST_ARGS=	-d ${WRKSRC}/src --quiet -E ${PATCH_DIST_STRIP}
CONFIGURE_ENV=	JED_ROOT=${PREFIX}/lib/jed
ALL_TARGET=	all getmail ${XJED}
INSTALL_TARGET=	install
WRKSRC=		${WRKDIR}/jed
MAN1=		jed.1 rgrep.1

pre-install:
	${LN} -sf ${WRKSRC}/autoconf/mkinsdir.sh  ${WRKSRC}/

post-install:
	strip ${PREFIX}/bin/jed
	strip ${PREFIX}/bin/rgrep
	strip ${PREFIX}/lib/jed/bin/getmail
.if defined(XJED)
	strip ${PREFIX}/bin/xjed
.endif
	${CP} -R ${WRKSRC}/lib/* ${PREFIX}/lib/jed/lib
	${INSTALL_DATA} ${WRKSRC}/info/jed.* ${PREFIX}/info
	-${RMDIR} ${PREFIX}/lib/jed/info
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/jed
	${INSTALL_DATA} ${WRKSRC}/doc/README ${WRKSRC}/doc/*.txt \
		${PREFIX}/share/doc/jed
	install-info --section="Miscellaneous" \
		--entry="* JED: (jed).			JED editor documentation." \
		${PREFIX}/info/jed.info ${PREFIX}/info/dir
.endif

.include <bsd.port.mk>
