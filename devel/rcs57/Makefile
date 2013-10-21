# $FreeBSD$

PORTNAME=	rcs
PORTVERSION=	5.7
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMESUFFIX=	57

MAINTAINER=	cy@FreeBSD.org
COMMENT=	Version control system (as was in FreeBSD prior to removal)

OPTIONS_DEFINE=	FREEBSD
OPTIONS_DEFAULT=	FREEBSD
FREEBSD_DESC=	Apply FreeBSD patches

CONFLICTS=	rcs-5.[89]*
LICENSE=	GPLv2

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

MAN1=	ci.1 co.1 ident.1 merge.1 rcs.1 rcsclean.1 rcsdiff.1 rcsintro.1 \
	rcsmerge.1 rlog.1
MAN5=	rcsfile.5

NO_STAGE=	yes

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MFREEBSD}
EXTRA_PATCHES+=	${FILESDIR}/freebsd-src-ident.c \
		${FILESDIR}/freebsd-src-maketime.c \
		${FILESDIR}/freebsd-src-rcsbase.h \
		${FILESDIR}/freebsd-src-rcsedit.c \
		${FILESDIR}/freebsd-src-rcsfnms.c \
		${FILESDIR}/freebsd-src-rcskeep.c \
		${FILESDIR}/freebsd-src-rcskeys.c \
		${FILESDIR}/freebsd-src-rcsrev.c \
		${FILESDIR}/freebsd-src-rcsutil.c \
		${FILESDIR}/freebsd-src-rcsdiff.c \
		${FILESDIR}/freebsd-src-rlog.c

.endif

.include <bsd.port.post.mk>
