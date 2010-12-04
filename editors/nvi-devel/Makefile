# New ports collection makefile for:	nvi-devel
# Date created:			6 July 2001
# Whom:				dd
#
# $FreeBSD$
#

PORTNAME=	nvi
PORTVERSION=	1.81.6
PORTREVISION=	3
CATEGORIES=	editors
MASTER_SITES=	http://www.kotnet.org/~skimo/nvi/devel/

MAINTAINER=	johans@FreeBSD.org
COMMENT=	Development snapshot of the world-renown nvi editor

CONFLICTS=	nvi-m17n-[0-9]*

OPTIONS=	WIDECHAR "Enable wide-character support (UTF-8)" On

USE_BZIP2=		yes
WRKSRC=			${WRKDIR}/${DISTNAME}/build.unix
USE_AUTOTOOLS=		libtool
USE_LDCONFIG=		yes
USE_ICONV=		yes
USE_BDB=		3
CONFIGURE_ARGS+=	--with-db-prefix=${LOCALBASE} \
			--program-prefix=n
CONFIGURE_ENV=		CPPFLAGS="-I${LOCALBASE}/include -L${LOCALBASE}/lib"
CONFIGURE_SCRIPT=	../dist/configure
MAN1=			nex.1 nvi.1 nview.1

.include <bsd.port.options.mk>

.if defined(WITH_WIDECHAR)
CONFIGURE_ARGS+=	--enable-widechar
.endif

# configure is 555, so you can't do a "make configure" as non-root.
post-patch:
	${REINPLACE_CMD} -e 's,%%LIBTOOL%%,${LIBTOOL},g ; \
		s,%%LTMAIN%%,${LTMAIN},g' ${WRKSRC}/../dist/configure
	@${CHMOD} 755 ${WRKSRC}/../dist/configure

post-install:
.for __p in nex nvi nview
	@# XXX: Hack the Makefile in the distribution so this isn't necessary.
	${RM} ${PREFIX}/man/cat1/${__p}.0
.endfor

.include <bsd.port.mk>
