# New ports collection makefile for:	nvi-devel
# Date created:			6 July 2001
# Whom:				dd
#
# $FreeBSD$
#

PORTNAME=	nvi
PORTVERSION=	1.81.5
PORTREVISION=	3
CATEGORIES=	editors
MASTER_SITES=	http://www.kotnet.org/~skimo/nvi/devel/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	dd

MAINTAINER=	dd@FreeBSD.org
COMMENT=	Development snapshot of the world-renown nvi editor

BUILD_DEPENDS=	iconv:${PORTSDIR}/converters/libiconv
LIB_DEPENDS=	db3.3:${PORTSDIR}/databases/db3

USE_BZIP2=		yes
WRKSRC=			${WRKDIR}/${DISTNAME}/build.unix
GNU_CONFIGURE=		yes
INSTALLS_SHLIB=		yes
CONFIGURE_ARGS+=	--with-db3=${LOCALBASE}
CONFIGURE_SCRIPT=	../dist/configure
MAN1=			ex.1 vi.1 view.1

# XXX: nvi doesn't really need sys/select.h, but I don't think the
# build should break when it includes it (this happens on RELENG_4;
# sys/select.h is effectively empty on -current).
post-configure:
	${ECHO_CMD} "#undef HAVE_SYS_SELECT_H" >> ${WRKSRC}/config.h

post-install:
.for __p in ex vi view
	@# XXX: Hack the Makefile in the distribution so this isn't necessary.
	${RM} ${PREFIX}/man/cat1/${__p}.0
.endfor

.include <bsd.port.mk>
