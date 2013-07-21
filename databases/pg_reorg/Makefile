# Created by: Alexander Pyhalov <alp@sfedu.ru>
# $FreeBSD$

PORTNAME=	pg_reorg
PORTVERSION=	1.1.8
CATEGORIES=	databases
MASTER_SITES=	http://pgfoundry.org/frs/download.php/3395/

MAINTAINER=	alp@sfedu.ru
COMMENT=	PostgreSQL utility to reorganize tables

LICENSE=	BSD

DESTINY=	${WRKDIR}/destino
MAKE_ENV=	USE_PGXS=0 \
		DESTDIR=${DESTINY}
USES=		gmake
USE_PGSQL=	yes

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DESTINY}${DOCSDIR}
	@(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} \* ${DESTINY}${DOCSDIR}/)
.endif
	${CP} -pR ${DESTINY}${PREFIX}/ ${PREFIX}/
	@cd ${DESTINY}${PREFIX}; ${FIND} * \( -type f -or -type l \) | \
	   ${SORT} > ${WRKDIR}/PLIST.all
	@cd ${DESTINY}${PREFIX}; ${FIND} * -type d | ${AWK} '/\//' | ${SORT} -r | \
	   ${SED} -e '/lib\/postgresql$$/d' -e '/share\/doc$$/d' \
	   -e '/share\/postgresql$$/d' -e '/share\/postgresql\/extension$$/d' \
	   -e 's/^/@dirrm /g' >> ${WRKDIR}/PLIST.all
	@echo "@unexec rmdir %D/lib/postgresql 2>/dev/null || true" >> ${WRKDIR}/PLIST.all
	@echo "@unexec rmdir %D/share/doc 2>/dev/null || true" >> ${WRKDIR}/PLIST.all
	@echo "@unexec rmdir %D/share/postgresql/extension 2>/dev/null || true" >> ${WRKDIR}/PLIST.all
	@echo "@unexec rmdir %D/share/postgresql 2>/dev/null || true" >> ${WRKDIR}/PLIST.all
	@${CAT} ${WRKDIR}/PLIST.all >> ${TMPPLIST}

.include <bsd.port.mk>
