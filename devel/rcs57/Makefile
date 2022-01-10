PORTNAME=	rcs
PORTVERSION=	5.7
CATEGORIES=	devel
MASTER_SITES=	GNU
PKGNAMESUFFIX=	57

MAINTAINER=	cy@FreeBSD.org
COMMENT=	Version control system (as was in FreeBSD prior to removal)

LICENSE=	GPLv2

CONFLICTS=	rcs

OPTIONS_DEFINE=	FREEBSD
OPTIONS_DEFAULT=	FREEBSD
FREEBSD_DESC=	Apply FreeBSD patches

USES=		desthack gmake
GNU_CONFIGURE=	yes

FREEBSD_EXTRA_PATCHES+=	${FILESDIR}/freebsd-src-ident.c \
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

.include <bsd.port.mk>
