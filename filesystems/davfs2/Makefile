PORTNAME=	davfs2
PORTVERSION=	1.7.2
CATEGORIES=	filesystems www
MASTER_SITES=	SAVANNAH \
		https://github.com/alisarctl/davfs2/releases/download/rel-${PORTVERSION:S/./-/g}/
PKGNAMEPREFIX=	fusefs-

MAINTAINER=	ali.abdallah@suse.com
COMMENT=	FUSE filesystem to access WebDAV servers
WWW=		http://savannah.nongnu.org/projects/davfs2 \
		https://github.com/alisarctl

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/AUTHORS

LIB_DEPENDS=	libexpat.so:textproc/expat2 \
		libneon.so:www/neon

USES=		gmake iconv ssl
GNU_CONFIGURE=	yes

USERS=		${PORTNAME}
GROUPS=		${PORTNAME}

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext-runtime
NLS_CONFIGURE_OFF=	--disable-nls

post-patch:
	@${REINPLACE_CMD} -e 's, 36, ${:!seq 36 39!},' ${WRKSRC}/configure

post-stage:
	${CHMOD} -s ${STAGEDIR}${PREFIX}/sbin/mount.davfs
	cd ${STAGEDIR}${DOCSDIR} && ${RM} AUTHORS COPYING INSTALL
.for f in davfs2.conf secrets
	cd ${STAGEDIR}${ETCDIR} && ${MV} ${f} ${f}.sample
.endfor

.include <bsd.port.mk>
