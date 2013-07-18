# Created by: dd
# $FreeBSD$

PORTNAME=	nvi
PORTVERSION=	1.81.6
PORTREVISION=	5
CATEGORIES=	editors
MASTER_SITES=	http://garage.linux.student.kuleuven.be/~skimo/nvi/devel/ \
		http://www.kotnet.org/~skimo/nvi/devel/

MAINTAINER=	johans@FreeBSD.org
COMMENT=	Development snapshot of the world-renown nvi editor

CONFLICTS_INSTALL=	nvi-m17n-[0-9]* xnview-[0-9]*

OPTIONS_DEFINE=	WIDECHAR
OPTIONS_DEFAULT=WIDECHAR
WIDECHAR_DESC=	Enable wide-character support (UTF-8)

USE_BZIP2=		yes
WRKSRC=			${WRKDIR}/${DISTNAME}/build.unix
USE_AUTOTOOLS=		libtool
USE_LDCONFIG=		yes
USES=			iconv
USE_BDB=		42+
CONFIGURE_ARGS+=	--with-db-prefix=${LOCALBASE} \
			--program-prefix=n
CONFIGURE_SCRIPT=	../dist/configure
MAN1=			nex.1 nvi.1 nview.1

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MWIDECHAR}
CONFIGURE_ARGS+=	--enable-widechar
.endif

CPPFLAGS+=		-I${BDB_INCLUDE_DIR} -I${LOCALBASE}/include
LDFLAGS+=		-L${BDB_LIB_DIR} -L${LOCALBASE}/lib

# configure is 555, so you can't do a "make configure" as non-root.
post-patch:
	${REINPLACE_CMD} -e 's,%%LIBTOOL%%,${LIBTOOL},g ; \
		s,%%LTMAIN%%,${LTMAIN},g ; \
		s,-ldb,-l${BDB_LIB_NAME},g' ${WRKSRC}/../dist/configure
	@${CHMOD} 755 ${WRKSRC}/../dist/configure

post-install:
.for __p in nex nvi nview
	@# XXX: Hack the Makefile in the distribution so this isn't necessary.
	${RM} ${PREFIX}/man/cat1/${__p}.0
.endfor

.include <bsd.port.mk>
