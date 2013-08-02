# Created by: mat
# $FreeBSD$

PORTNAME=	Alzabo
PORTVERSION=	0.92
CATEGORIES=	devel databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Data modelling tool and RDBMS-OO mapper

BUILD_DEPENDS=	p5-Exception-Class>=0:${PORTSDIR}/devel/p5-Exception-Class \
		p5-Class-Factory-Util>=0:${PORTSDIR}/devel/p5-Class-Factory-Util \
		p5-Params-Validate>=0:${PORTSDIR}/devel/p5-Params-Validate \
		p5-Tie-IxHash>=0:${PORTSDIR}/devel/p5-Tie-IxHash \
		p5-DBI>=0:${PORTSDIR}/databases/p5-DBI
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	modbuild

MAN3=		\
		Alzabo.3 \
		Alzabo::BackCompat.3 \
		Alzabo::ChangeTracker.3 \
		Alzabo::Column.3 \
		Alzabo::ColumnDefinition.3 \
		Alzabo::Config.3 \
		Alzabo::Create.3 \
		Alzabo::Create::Column.3 \
		Alzabo::Create::ColumnDefinition.3 \
		Alzabo::Create::ForeignKey.3 \
		Alzabo::Create::Index.3 \
		Alzabo::Create::Schema.3 \
		Alzabo::Create::Table.3 \
		Alzabo::Debug.3 \
		Alzabo::Design.3 \
		Alzabo::Driver.3 \
		Alzabo::Driver::MySQL.3 \
		Alzabo::Driver::PostgreSQL.3 \
		Alzabo::Exceptions.3 \
		Alzabo::FAQ.3 \
		Alzabo::ForeignKey.3 \
		Alzabo::Index.3 \
		Alzabo::Intro.3 \
		Alzabo::MethodMaker.3 \
		Alzabo::MySQL.3 \
		Alzabo::PostgreSQL.3 \
		Alzabo::QuickRef.3 \
		Alzabo::RDBMSRules.3 \
		Alzabo::RDBMSRules::MySQL.3 \
		Alzabo::RDBMSRules::PostgreSQL.3 \
		Alzabo::Runtime.3 \
		Alzabo::Runtime::Column.3 \
		Alzabo::Runtime::ColumnDefinition.3 \
		Alzabo::Runtime::Cursor.3 \
		Alzabo::Runtime::ForeignKey.3 \
		Alzabo::Runtime::Index.3 \
		Alzabo::Runtime::InsertHandle.3 \
		Alzabo::Runtime::JoinCursor.3 \
		Alzabo::Runtime::Row.3 \
		Alzabo::Runtime::RowCursor.3 \
		Alzabo::Runtime::RowState::Deleted.3 \
		Alzabo::Runtime::RowState::InCache.3 \
		Alzabo::Runtime::RowState::Live.3 \
		Alzabo::Runtime::RowState::Potential.3 \
		Alzabo::Runtime::Schema.3 \
		Alzabo::Runtime::Table.3 \
		Alzabo::Runtime::UniqueRowCache.3 \
		Alzabo::SQLMaker.3 \
		Alzabo::SQLMaker::MySQL.3 \
		Alzabo::SQLMaker::PostgreSQL.3 \
		Alzabo::Schema.3 \
		Alzabo::Table.3 \
		Alzabo::Utils.3

.if !defined(NOPORTDOCS)
EXAMPLES=	eg/alzabo_grep eg/alzabo_to_ascii eg/convert.pl eg/reverse_cardinality.pl
EXAMPLESMASON=	mason/widgets/edit_field_checkbox mason/widgets/edit_field_text_input mason/widgets/edit_field_textarea mason/widgets/fk_to_one_select mason/widgets/insert mason/widgets/insert_or_update mason/widgets/update
PORTDOCS=	README Changes TODO

post-install:
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${EXAMPLES:S|^|${WRKSRC}/|} ${EXAMPLESDIR}
	@${MKDIR} ${EXAMPLESDIR}/mason
	@${INSTALL_DATA} ${EXAMPLESMASON:S|^|${WRKSRC}/|} ${EXAMPLESDIR}/mason
	@${ECHO_MSG} "===> Examples installed in ${EXAMPLESDIR}."
	@${FIND} -P ${EXAMPLESDIR} ! -type d 2>/dev/null | \
		${SED} -ne 's,^${PREFIX}/,,p' >> ${TMPPLIST}
	@${FIND} -P -d ${EXAMPLESDIR} -type d 2>/dev/null | \
		${SED} -ne 's,^${PREFIX}/,@dirrm ,p' >> ${TMPPLIST}
.endif

.include <bsd.port.mk>
