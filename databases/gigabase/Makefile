# ports collection makefile for:	gigabase
# Date created:			15 August 2000
# Whom:				Sergey Osokin aka oZZ <ozz@FreeBSD.org.ru>
#
# $FreeBSD$
#

PORTNAME=	gigabase
PORTVERSION=	2.30
CATEGORIES=	databases
MASTER_SITES=	http://www.ispras.ru/~knizhnik/

MAINTAINER=	ozz@FreeBSD.org.ru

WRKSRC=		${WRKDIR}/${PORTNAME}
INSTALLS_SHLIB=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-shared --build=$(ARCH} --host=unknown-freebsd --target=${OSREL}

do-install:
	@${MKDIR} -m 755 ${PREFIX}/include/${PORTNAME}
	@for f in gigabase.h stdtp.h class.h database.h cursor.h reference.h \
		wwwapi.h array.h file.h hashtab.h btree.h sync.h query.h \
		datetime.h pagepool.h blob.h container.h cli.h ; do \
		${INSTALL} -C -o root -g wheel -m 0644 ${WRKSRC}/$$f \
		${PREFIX}/include/${PORTNAME}/$$f ;\
	done
	@${INSTALL} -C -o root -g wheel -m 0755 -s ${WRKSRC}/.libs/subsql \
		${PREFIX}/bin/subsql
	@for f in libgigabase_r.a libgigabase_r.so.2 libcli_r.a libcli_r.so.2 ; do \
		${INSTALL} -C -o root -g wheel -m 0644 ${WRKSRC}/.libs/$$f \
		${PREFIX}/lib/$f ;\
	done

.include <bsd.port.mk>
