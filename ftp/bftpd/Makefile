# Created by: will

PORTNAME=	bftpd
PORTVERSION=	5.7
CATEGORIES=	ftp
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Very configurable FTP server that can do chroot easily

LICENSE=	GPLv2

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-pam
# Fix build with clang 11
CFLAGS+=	-fcommon

USES=		autoreconf gmake

WRKSRC=	${WRKDIR}/${PORTNAME}

PLIST_FILES=	sbin/${PORTNAME} etc/${PORTNAME}.conf.sample \
		man/man8/bftpd.8.gz
PORTDOCS=	en pl sk

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's,/etc/bftpd.conf,${PREFIX}/etc/bftpd.conf,' \
		${WRKSRC}/mypaths.h
	@${REINPLACE_CMD} -e 's, -ldl,,g' ${WRKSRC}/configure.in
	@${FIND} ${WRKSRC} -name CVS | ${XARGS} ${RM} -r

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/sbin/
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.8 ${STAGEDIR}${MAN8PREFIX}/man/man8/
	${INSTALL_DATA} ${WRKSRC}/bftpd.conf ${STAGEDIR}${PREFIX}/etc/bftpd.conf.sample
	@cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
