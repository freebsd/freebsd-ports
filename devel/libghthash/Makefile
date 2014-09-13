# Created by: ijliao
# $FreeBSD$

PORTNAME=	libghthash
PORTVERSION=	0.6.2
PORTREVISION=	5
CATEGORIES=	devel
MASTER_SITES=	http://www.ipd.bth.se/ska/sim_home/filer/

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Generic Hash Table

OPTIONS_DEFINE=	DOCS EXAMPLES

USES=		libtool
GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	aclocal autoheader automake autoconf libtoolize
AUTOMAKE_ARGS=	-a -c -f
USE_LDCONFIG=	yes

PLIST_FILES=	include/ght_hash_table.h \
		lib/libghthash.a \
		lib/libghthash.so \
		lib/libghthash.so.1 \
		lib/libghthash.so.1.1.0 \
		man/man3/ght_create.3.gz \
		man/man3/ght_finalize.3.gz \
		man/man3/ght_first.3.gz \
		man/man3/ght_first_keysize.3.gz \
		man/man3/ght_get.3.gz \
		man/man3/ght_insert.3.gz \
		man/man3/ght_next.3.gz \
		man/man3/ght_next_keysize.3.gz \
		man/man3/ght_remove.3.gz

PORTDOCS=	*
PORTEXAMPLES=	*

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/html && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} \*.c ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
