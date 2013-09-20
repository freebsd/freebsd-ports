# Created by: Eygene Ryabinkin
# $FreeBSD$

PORTNAME=	lxr
PORTVERSION=	0.10.2
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/stable/${PORTNAME}-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	rea@FreeBSD.org
COMMENT=	Source code indexer and cross-referencer

BUILD_DEPENDS=	exctags:${PORTSDIR}/devel/ctags \
		swish-e:${PORTSDIR}/www/swish-e \
		p5-File-MMagic>=0:${PORTSDIR}/devel/p5-File-MMagic

PATCH_STRIP=	-p1

USES=		perl5
NO_BUILD=	yes

OPTIONS_DEFINE=	DOCS
OPTIONS_SINGLE=	DB
OPTIONS_SINGLE_DB=	PGSQL MYSQL
OPTIONS_DEFAULT=	PGSQL

# Name prefix for database tables, indexes, sequences and other stuff.
DB_PREFIX=	lxr

# Installation directory
.if !defined(LXRDIR)
.if defined(APACHE_DATADIR)
LXRTOPDIR=	${APACHE_DATADIR}/data
.else
LXRTOPDIR=	${PREFIX}/www/data
.endif # defined(APACHE_DATADIR)
LXRDIR=	${LXRTOPDIR}/lxr
.endif # !defined(LXRDIR)

PLIST_SUB+=	LXRDIR=${LXRDIR:S!^${PREFIX}/!!}
PLIST_SUB+=	LXRTOPDIR=${LXRTOPDIR:S!^${PREFIX}/!!}
SUB_LIST+=	LXRDIR=${LXRDIR}
SUB_FILES+=	upgrade-0.9.10-postgres upgrade-0.9.10-mysql

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPGSQL}
BUILD_DEPENDS+=	p5-DBD-Pg>=0:${PORTSDIR}/databases/p5-DBD-Pg
MSG_FILES+=	pkg_message.postgresql
DB_DRIVER=	Pg
.endif # ${PORT_OPTIONS:MPGSQL}

.if ${PORT_OPTIONS:MMYSQL}
BUILD_DEPENDS+=	p5-DBD-mysql>=0:${PORTSDIR}/databases/p5-DBD-mysql
MSG_FILES+=	pkg_message.mysql
DB_DRIVER=	mysql
.endif # ${PORT_OPTIONS:MMYSQL}

MSG_FILES+=	pkg_message

SUB_FILES+=	${MSG_FILES}

LXR_SCRIPTS=	diff \
		genxref \
		ident \
		search \
		source

LXR_CONF=	swish-e.conf \
		initdb-postgres \
		initdb-mysql

LXR_DOCS=	BUGS \
		CREDITS.txt \
		ChangeLog \
		HACKING \
		INSTALL \
		LICENSE \
		RELEASING

post-patch:
	@${REINPLACE_CMD} \
	    -e"s|'glimpsebin'|# 'glimpsebin'|" \
	    -e"s|'glimpseindex'|# 'glimpseindex'|" \
	    -e"s|'/usr/local/bin/swish-e'|'${LOCALBASE}/bin/swish-e'|" \
	    -e"s|'/usr/bin/ctags'|'${LOCALBASE}/bin/exctags'|" \
	    -e"s|'/path/to/lib/LXR/Lang/generic.conf'|'${SITE_PERL}/LXR/Lang/generic.conf'|" \
	    -e"s|'/path/to/lib/LXR/Lang/ectags.conf'|'${SITE_PERL}/LXR/Lang/ectags.conf'|" \
	    -e"s|'dbi:mysql:|'dbi:${DB_DRIVER}:|" \
	    -e's|'lxr_'|'${DB_PREFIX}_'|g' \
	    ${WRKSRC}/templates/lxr.conf && \
	    ${RM} -f ${WRKSRC}/templates/lxr.conf.bak
	@${REINPLACE_CMD} \
	    -e's|lxr_|${DB_PREFIX}_|g' \
	    ${WRKSRC}/initdb-postgres
	@${REINPLACE_CMD} \
	    -e's|lxr|${DB_PREFIX}|g' \
	    ${WRKSRC}/initdb-mysql

do-install:
	${MKDIR} ${LXRDIR}
.for f in ${LXR_SCRIPTS}
	${INSTALL_SCRIPT} ${WRKSRC}/${f} ${LXRDIR}
.endfor # ${LXR_SCRIPTS}
.for f in ${LXR_CONF}
	${INSTALL_DATA} ${WRKSRC}/${f} ${LXRDIR}
.endfor # ${LXR_CONF}
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
.for f in ${LXR_DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor # ${LXR_DOCS}
.endif # ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${PREFIX}/${SITE_PERL_REL}
	${INSTALL_DATA} ${WRKSRC}/Local.pm ${PREFIX}/${SITE_PERL_REL}
	${INSTALL_DATA} ${WRKSRC}/LXRversion.pm ${PREFIX}/${SITE_PERL_REL}
	${TAR} -C ${WRKSRC}/lib -cf - --exclude '*.orig' LXR | ${TAR} -C ${PREFIX}/${SITE_PERL_REL} -xf -
	${TAR} -C ${WRKSRC} -cf - --exclude '*.orig' templates | ${TAR} -C ${LXRDIR} -xf -
	${CHMOD} 640 ${LXRDIR}/templates/lxr.conf
	${INSTALL_DATA} ${WRKDIR}/upgrade-0.9.10-postgres ${LXRDIR}
	${INSTALL_DATA} ${WRKDIR}/upgrade-0.9.10-mysql ${LXRDIR}

post-install:
	@${ECHO}
	@${ECHO} "******************** Installation tips ********************"
	@${ECHO}
.for f in ${MSG_FILES}
	@${CAT} ${WRKDIR}/${f}
.endfor # ${MSG_FILES}

.include <bsd.port.mk>
