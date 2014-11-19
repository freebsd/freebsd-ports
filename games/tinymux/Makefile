# Created by: cjohnson
# $FreeBSD$

PORTNAME=	tinymux
PORTVERSION=	2.10.1.${PATCHLEVEL}
CATEGORIES=	games net
MASTER_SITES=	GOOGLE_CODE
DISTNAME=	mux-${PORTVERSION}.unix

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Multi-Player FreeForm adventure Program

LICENSE=	ART10
LICENSE_FILE=	${WRKSRC}/copyright.h

WRKSRC=		${WRKDIR}/mux2.10/src

USES=		gmake
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lcrypto

PATCHLEVEL=	12

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS FIRANMUX MEMORY_BASED REALITY_LVLS SELFCHECK SSL WOD_REALMS
OPTIONS_DEFAULT=	ASYNCHRONOUS_SQL SSL REALITY_LVLS WOD_REALMS
OPTIONS_SUB=	yes

OPTIONS_RADIO=	MYSQL
OPTIONS_RADIO_MYSQL=	ASYNCHRONOUS_SQL INLINE_SQL

ASYNCHRONOUS_SQL_DESC=	MySQL asynchronous support is unique to TinyMUX
FIRANMUX_DESC=		Firan MUX via Firan database (need MEMORY_BASED)
INLINE_SQL_DESC=	MySQL support compatible with PennMUSH, TinyMUSH 3.x
MEMORY_BASED_DESC=	Memory Based Database support
REALITY_LVLS_DESC=	Reality Levels support
SELFCHECK_DESC=		Enable expensive self-checking
WOD_REALMS_DESC=	World of Darkness Realms support

ASYNCHRONOUS_SQL_CONFIGURE_ENABLE=	stubslave
FIRANMUX_CONFIGURE_ENABLE=	firanmux
INLINE_SQL_CONFIGURE_ENABLE=	inlinesql
MEMORY_BASED_CONFIGURE_ENABLE=	memorybased
REALITY_LVLS_CONFIGURE_ENABLE=	realitylvls
SELFCHECK_CONFIGURE_ENABLE=	selfcheck
SSL_CONFIGURE_ENABLE=	ssl
WOD_REALMS_CONFIGURE_ENABLE=	wodrealms

SUB_FILES=	${PORTNAME} pkg-deinstall pkg-message

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MASYNCHRONOUS_SQL} || ${PORT_OPTIONS:MINLINE_SQL}
USE_MYSQL=	yes
CONFIGURE_ARGS+=	--with-mysql-include=${LOCALBASE}/include/mysql \
			--with-mysql-libs=${LOCALBASE}/lib/mysql
.endif

.if ${PORT_OPTIONS:MFIRANMUX}
.if ${PORT_OPTIONS:MREALITY_LVLS} || ${PORT_OPTIONS:MWOD_REALMS}
IGNORE=	FIRANMUX is incompatible with both WOD_REALMS and REALITY_LVLS
.endif
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|@LIBS@|@LDFLAGS@ @LIBS@|; \
		 s|^OPTIM =.*|OPTIM = @CPPFLAGS@|' ${WRKSRC}/Makefile.in

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/

.for file in netmux slave
	${INSTALL_PROGRAM} ${WRKSRC}/${file} ${STAGEDIR}${PREFIX}/sbin/
.endfor
	${LN} -sf ${PREFIX}/sbin/netmux ${STAGEDIR}${PREFIX}/bin/dbconvert
	${INSTALL_DATA} ${WRKSRC}/libmux.so ${STAGEDIR}${PREFIX}/lib/
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libmux.so

	@${MKDIR} ${STAGEDIR}${ETCDIR}
.for file in alias.conf compat.conf mux.config netmux.conf
	${INSTALL_DATA} ${WRKSRC}/../game/${file} \
		${STAGEDIR}${ETCDIR}/${file}.sample
.endfor

.if ${PORT_OPTIONS:MSSL}
	${INSTALL_DATA} ${WRKSRC}/../game/muxssl.conf \
		${STAGEDIR}${ETCDIR}/muxssl.conf.sample
.endif

.for d in data text
	@(cd ${WRKSRC}/../game && ${COPYTREE_SHARE} ${d} ${STAGEDIR}${DATADIR})
.endfor
	@${CHMOD} 775 ${STAGEDIR}${DATADIR}/data

.for file in Backup Startmux _backupflat.sh
	${INSTALL_SCRIPT} ${WRKSRC}/../game/${file} \
		${STAGEDIR}${DATADIR}
.endfor

	cd ${WRKSRC}/.. && ${COPYTREE_SHARE} \
		"ATTACK CHANGES MODULES NOTES README REALITY REALITY.SETUP SGP SQL SSL docs" \
		${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
