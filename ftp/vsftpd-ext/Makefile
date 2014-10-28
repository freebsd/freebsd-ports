# Created by: Maxim Ignatenko
# $FreeBSD$

PORTNAME=	vsftpd-ext
PORTVERSION=	${UPSTREAMVERSION}.${EXTVERSION}
PORTREVISION=	1
CATEGORIES=	ftp ipv6
MASTER_SITES=	http://vsftpd.devnet.ru/files/${UPSTREAMVERSION}/ext.${EXTVERSION}/
PKGNAMESUFFIX?=	${SSL_SUFFIX}${PKGNAMESUFFIX2}
DISTNAME=	vsFTPd-${UPSTREAMVERSION}-ext${EXTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	xjflyttp@gmail.com
COMMENT=	FTP daemon that aims to be "very secure". Extended build

LICENSE=	GPLv2

UPSTREAMVERSION=3.0.2
EXTVERSION=	1

USES+=		gmake
WRKSRC=		${WRKDIR}/vsFTPd-${UPSTREAMVERSION}-ext.${EXTVERSION}
ALL_TARGET=	vsftpd

USERS=		ftp
GROUPS=		ftp

DOCFILES=	AUDIT BENCHMARKS BUGS Changelog FAQ INSTALL LICENSE \
		README README.security README.ssl REFS REWARD \
		SIZE SPEED TODO TUNING

OPTIONS_DEFINE=	RC_SCRIPT VSFTPD_SSL DOCS
OPTIONS_DEFAULT=RC_SCRIPT DOCS
RC_SCRIPT_DESC=	install RC_SCRIPT

VSFTPD_SSL_DESC=Include support for SSL

CONFLICTS=	vsftpd-3* vsftpd${SSL_SUFFIX}${PKGNAMESUFFIX2}-3*

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} < 902001
BUILD_DEPENDS+=	clang33:${PORTSDIR}/lang/clang33
CC=		clang33
.endif

.if ${PORT_OPTIONS:MRC_SCRIPT}
USE_RC_SUBR=	vsftpd
.endif

VSFTPD_OPTIMIZED=	${CFLAGS:M-O*}
.if defined(CFLAGS) && !empty(VSFTPD_OPTIMIZED)
VSFTPD_NO_OPTIMIZED=	-e "s|-O2 ||"
.endif

.if ${PORT_OPTIONS:MVSFTPD_SSL} && !defined(WITHOUT_SSL)
.include "${PORTSDIR}/Mk/bsd.openssl.mk"
SSL_SUFFIX=	-ssl
CFLAGS+=	-I${OPENSSLINC}
LDFLAGS+=	-L${OPENSSLLIB}
.endif

do-configure:
.if ${PORT_OPTIONS:MVSFTPD_SSL} && !defined(WITHOUT_SSL)
	${REINPLACE_CMD} -e \
		"s|#undef VSF_BUILD_TCPWRAPPERS|#define VSF_BUILD_TCPWRAPPERS 1|" \
		-e "s|#undef VSF_BUILD_SSL|#define VSF_BUILD_SSL 1|" \
		${WRKSRC}/builddefs.h
.else
	${REINPLACE_CMD} -e \
		"s|#undef VSF_BUILD_TCPWRAPPERS|#define VSF_BUILD_TCPWRAPPERS 1|" \
		${WRKSRC}/builddefs.h
.endif
	${REINPLACE_CMD} -e "s|\"vsftpd.conf\"|\"${PREFIX}/etc/vsftpd.conf\"|" \
		${WRKSRC}/defs.h
	${REINPLACE_CMD} -e "s|/etc/v|${PREFIX}/etc/v|" \
		${WRKSRC}/vsftpd.8 ${WRKSRC}/vsftpd.conf.5
	${REINPLACE_CMD} -e "s|/usr/share/empty|${PREFIX}/share/vsftpd/empty|" \
		${WRKSRC}/tunables.c
	${REINPLACE_CMD} ${VSFTPD_NO_OPTIMIZED} \
		-e '/^CC/s/=/?=/' \
		-e '/^CFLAGS/{s/=/+=/;s/-O[0-9]//;}' \
		-e '/^LIBS/s|=.*|= `./vsf_findlibs.sh`|' \
		-e '/^LINK/s/=.*/=/' \
		-e 's|-Werror||' \
		${WRKSRC}/Makefile
	${REINPLACE_CMD} -e '/-lutil/d' ${WRKSRC}/vsf_findlibs.sh

	@${ECHO_CMD} "secure_chroot_dir=${PREFIX}/share/vsftpd/empty" >> \
		${WRKSRC}/vsftpd.conf
	@${ECHO_CMD} >>${WRKSRC}/vsftpd.conf ""
	@${ECHO_CMD} >>${WRKSRC}/vsftpd.conf \
		"# If using vsftpd in standalone mode, uncomment the next two lines:"
	@${ECHO_CMD} >>${WRKSRC}/vsftpd.conf "# listen=YES"
	@${ECHO_CMD} >>${WRKSRC}/vsftpd.conf "# background=YES"
	${REINPLACE_CMD} -e "s|^listen=.*|listen=NO|" \
		${WRKSRC}/vsftpd.conf

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/vsftpd ${STAGEDIR}${PREFIX}/libexec/
	${INSTALL_DATA} ${WRKSRC}/vsftpd.conf ${STAGEDIR}${PREFIX}/etc/vsftpd.conf.sample
	${INSTALL_MAN} ${WRKSRC}/vsftpd.conf.5 ${STAGEDIR}${PREFIX}/man/man5/
	${INSTALL_MAN} ${WRKSRC}/vsftpd.8 ${STAGEDIR}${PREFIX}/man/man8/
	${MKDIR} ${STAGEDIR}/var/ftp ${STAGEDIR}${PREFIX}/share/vsftpd/empty
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOCFILES:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}/
.for i in EXAMPLE SECURITY
	${MKDIR} ${STAGEDIR}${DOCSDIR}/${i}
	${CP} -p -R -L ${WRKSRC}/${i}/./ ${STAGEDIR}${DOCSDIR}/${i}/
	${CHMOD} -R -L a+rX,go-w ${STAGEDIR}${DOCSDIR}/${i}/
.endfor
.endif

.include <bsd.port.mk>
