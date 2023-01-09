--- lib/external/pattern_language/lib/include/pl/core/token.hpp.orig	2023-01-09 11:44:49 UTC
+++ lib/external/pattern_language/lib/include/pl/core/token.hpp
@@ -151,14 +151,14 @@ namespace pl::core {
             bool global;
             std::string comment;
 
-            constexpr bool operator==(const DocComment &) const = default;
+            bool operator==(const DocComment &) const = default;
         };
 
         using Literal    = std::variant<char, bool, u128, i128, double, std::string, ptrn::Pattern *>;
         using ValueTypes = std::variant<Keyword, Identifier, Operator, Literal, ValueType, Separator, DocComment>;
+        // These changes are necessary for Clang
+        inline Token(Type type, auto value, u32 line, u32 column) : type(type), value(std::move(value)), line(line), column(column) {}
 
-        constexpr Token(Type type, auto value, u32 line, u32 column) : type(type), value(std::move(value)), line(line), column(column) {}
-
         [[nodiscard]] constexpr static inline bool isInteger(const ValueType &type) {
             return isUnsigned(type) || isSigned(type);
         }
@@ -227,134 +227,134 @@ namespace pl::core {
 
     namespace tkn {
 
-        constexpr inline Token createToken(const core::Token::Type type, const core::Token::ValueTypes &value) {
+        inline pl::core::Token createToken(const core::Token::Type type, const core::Token::ValueTypes &value) {
             return { type, value, 1, 1 };
         }
 
         namespace Keyword {
 
-            constexpr auto If           = createToken(core::Token::Type::Keyword, Token::Keyword::If);
-            constexpr auto Else         = createToken(core::Token::Type::Keyword, Token::Keyword::Else);
-            constexpr auto While        = createToken(core::Token::Type::Keyword, Token::Keyword::While);
-            constexpr auto For          = createToken(core::Token::Type::Keyword, Token::Keyword::For);
-            constexpr auto Return       = createToken(core::Token::Type::Keyword, Token::Keyword::Return);
-            constexpr auto Break        = createToken(core::Token::Type::Keyword, Token::Keyword::Break);
-            constexpr auto Continue     = createToken(core::Token::Type::Keyword, Token::Keyword::Continue);
-            constexpr auto Struct       = createToken(core::Token::Type::Keyword, Token::Keyword::Struct);
-            constexpr auto Enum         = createToken(core::Token::Type::Keyword, Token::Keyword::Enum);
-            constexpr auto Union        = createToken(core::Token::Type::Keyword, Token::Keyword::Union);
-            constexpr auto Function     = createToken(core::Token::Type::Keyword, Token::Keyword::Function);
-            constexpr auto Bitfield     = createToken(core::Token::Type::Keyword, Token::Keyword::Bitfield);
-            constexpr auto LittleEndian = createToken(core::Token::Type::Keyword, Token::Keyword::LittleEndian);
-            constexpr auto BigEndian    = createToken(core::Token::Type::Keyword, Token::Keyword::BigEndian);
-            constexpr auto Parent       = createToken(core::Token::Type::Keyword, Token::Keyword::Parent);
-            constexpr auto Namespace    = createToken(core::Token::Type::Keyword, Token::Keyword::Namespace);
-            constexpr auto Using        = createToken(core::Token::Type::Keyword, Token::Keyword::Using);
-            constexpr auto This         = createToken(core::Token::Type::Keyword, Token::Keyword::This);
-            constexpr auto In           = createToken(core::Token::Type::Keyword, Token::Keyword::In);
-            constexpr auto Out          = createToken(core::Token::Type::Keyword, Token::Keyword::Out);
-            constexpr auto Reference    = createToken(core::Token::Type::Keyword, Token::Keyword::Reference);
+            inline auto If           = createToken(core::Token::Type::Keyword, Token::Keyword::If);
+            inline auto Else         = createToken(core::Token::Type::Keyword, Token::Keyword::Else);
+            inline auto While        = createToken(core::Token::Type::Keyword, Token::Keyword::While);
+            inline auto For          = createToken(core::Token::Type::Keyword, Token::Keyword::For);
+            inline auto Return       = createToken(core::Token::Type::Keyword, Token::Keyword::Return);
+            inline auto Break        = createToken(core::Token::Type::Keyword, Token::Keyword::Break);
+            inline auto Continue     = createToken(core::Token::Type::Keyword, Token::Keyword::Continue);
+            inline auto Struct       = createToken(core::Token::Type::Keyword, Token::Keyword::Struct);
+            inline auto Enum         = createToken(core::Token::Type::Keyword, Token::Keyword::Enum);
+            inline auto Union        = createToken(core::Token::Type::Keyword, Token::Keyword::Union);
+            inline auto Function     = createToken(core::Token::Type::Keyword, Token::Keyword::Function);
+            inline auto Bitfield     = createToken(core::Token::Type::Keyword, Token::Keyword::Bitfield);
+            inline auto LittleEndian = createToken(core::Token::Type::Keyword, Token::Keyword::LittleEndian);
+            inline auto BigEndian    = createToken(core::Token::Type::Keyword, Token::Keyword::BigEndian);
+            inline auto Parent       = createToken(core::Token::Type::Keyword, Token::Keyword::Parent);
+            inline auto Namespace    = createToken(core::Token::Type::Keyword, Token::Keyword::Namespace);
+            inline auto Using        = createToken(core::Token::Type::Keyword, Token::Keyword::Using);
+            inline auto This         = createToken(core::Token::Type::Keyword, Token::Keyword::This);
+            inline auto In           = createToken(core::Token::Type::Keyword, Token::Keyword::In);
+            inline auto Out          = createToken(core::Token::Type::Keyword, Token::Keyword::Out);
+            inline auto Reference    = createToken(core::Token::Type::Keyword, Token::Keyword::Reference);
 
         }
 
         namespace Literal {
 
-            constexpr auto IdentifierValue   = [](const std::string &name = { }) -> Token           { return createToken(core::Token::Type::Identifier, Token::Identifier(name)); };
-            constexpr auto NumericValue      = [](const Token::Literal &value = { }) -> Token       { return createToken(core::Token::Type::Integer, value); };
-            constexpr auto StringValue       = [](const std::string &value = { }) -> Token          { return createToken(core::Token::Type::String, Token::Literal(value)); };
-            constexpr auto DocComment        = [](bool global, const std::string &value) -> Token   { return { core::Token::Type::DocComment, Token::DocComment { global, value }, 1, 1 }; };
+            inline auto IdentifierValue   = [](const std::string &name = { }) -> Token           { return createToken(core::Token::Type::Identifier, Token::Identifier(name)); };
+            inline auto NumericValue      = [](const Token::Literal &value = { }) -> Token       { return createToken(core::Token::Type::Integer, value); };
+            inline auto StringValue       = [](const std::string &value = { }) -> Token          { return createToken(core::Token::Type::String, Token::Literal(value)); };
+            inline auto DocComment        = [](bool global, const std::string &value) -> Token   { return { core::Token::Type::DocComment, Token::DocComment { global, value }, 1, 1 }; };
 
-            constexpr auto Identifier = createToken(core::Token::Type::Identifier, { });
-            constexpr auto Numeric = createToken(core::Token::Type::Integer, { });
-            constexpr auto String = createToken(core::Token::Type::String, { });
+            inline auto Identifier = createToken(core::Token::Type::Identifier, { });
+            inline auto Numeric = createToken(core::Token::Type::Integer, { });
+            inline auto String = createToken(core::Token::Type::String, { });
 
         }
 
         namespace Operator {
 
-            constexpr auto Plus                     = createToken(core::Token::Type::Operator, Token::Operator::Plus);
-            constexpr auto Minus                    = createToken(core::Token::Type::Operator, Token::Operator::Minus);
-            constexpr auto Star                     = createToken(core::Token::Type::Operator, Token::Operator::Star);
-            constexpr auto Slash                    = createToken(core::Token::Type::Operator, Token::Operator::Slash);
-            constexpr auto Percent                  = createToken(core::Token::Type::Operator, Token::Operator::Percent);
-            constexpr auto LeftShift                = createToken(core::Token::Type::Operator, Token::Operator::LeftShift);
-            constexpr auto RightShift               = createToken(core::Token::Type::Operator, Token::Operator::RightShift);
-            constexpr auto BitAnd                   = createToken(core::Token::Type::Operator, Token::Operator::BitAnd);
-            constexpr auto BitOr                    = createToken(core::Token::Type::Operator, Token::Operator::BitOr);
-            constexpr auto BitXor                   = createToken(core::Token::Type::Operator, Token::Operator::BitXor);
-            constexpr auto BitNot                   = createToken(core::Token::Type::Operator, Token::Operator::BitNot);
-            constexpr auto BoolEqual                = createToken(core::Token::Type::Operator, Token::Operator::BoolEqual);
-            constexpr auto BoolNotEqual             = createToken(core::Token::Type::Operator, Token::Operator::BoolNotEqual);
-            constexpr auto BoolLessThan             = createToken(core::Token::Type::Operator, Token::Operator::BoolLessThan);
-            constexpr auto BoolGreaterThan          = createToken(core::Token::Type::Operator, Token::Operator::BoolGreaterThan);
-            constexpr auto BoolLessThanOrEqual      = createToken(core::Token::Type::Operator, Token::Operator::BoolLessThanOrEqual);
-            constexpr auto BoolGreaterThanOrEqual   = createToken(core::Token::Type::Operator, Token::Operator::BoolGreaterThanOrEqual);
-            constexpr auto BoolAnd                  = createToken(core::Token::Type::Operator, Token::Operator::BoolAnd);
-            constexpr auto BoolOr                   = createToken(core::Token::Type::Operator, Token::Operator::BoolOr);
-            constexpr auto BoolNot                  = createToken(core::Token::Type::Operator, Token::Operator::BoolNot);
-            constexpr auto BoolXor                  = createToken(core::Token::Type::Operator, Token::Operator::BoolXor);
-            constexpr auto Dollar                   = createToken(core::Token::Type::Operator, Token::Operator::Dollar);
-            constexpr auto Colon                    = createToken(core::Token::Type::Operator, Token::Operator::Colon);
-            constexpr auto ScopeResolution          = createToken(core::Token::Type::Operator, Token::Operator::ScopeResolution);
-            constexpr auto TernaryConditional       = createToken(core::Token::Type::Operator, Token::Operator::TernaryConditional);
-            constexpr auto AddressOf                = createToken(core::Token::Type::Operator, Token::Operator::AddressOf);
-            constexpr auto SizeOf                   = createToken(core::Token::Type::Operator, Token::Operator::SizeOf);
-            constexpr auto At                       = createToken(core::Token::Type::Operator, Token::Operator::At);
-            constexpr auto Assign                   = createToken(core::Token::Type::Operator, Token::Operator::Assign);
+            inline auto Plus                     = createToken(core::Token::Type::Operator, Token::Operator::Plus);
+            inline auto Minus                    = createToken(core::Token::Type::Operator, Token::Operator::Minus);
+            inline auto Star                     = createToken(core::Token::Type::Operator, Token::Operator::Star);
+            inline auto Slash                    = createToken(core::Token::Type::Operator, Token::Operator::Slash);
+            inline auto Percent                  = createToken(core::Token::Type::Operator, Token::Operator::Percent);
+            inline auto LeftShift                = createToken(core::Token::Type::Operator, Token::Operator::LeftShift);
+            inline auto RightShift               = createToken(core::Token::Type::Operator, Token::Operator::RightShift);
+            inline auto BitAnd                   = createToken(core::Token::Type::Operator, Token::Operator::BitAnd);
+            inline auto BitOr                    = createToken(core::Token::Type::Operator, Token::Operator::BitOr);
+            inline auto BitXor                   = createToken(core::Token::Type::Operator, Token::Operator::BitXor);
+            inline auto BitNot                   = createToken(core::Token::Type::Operator, Token::Operator::BitNot);
+            inline auto BoolEqual                = createToken(core::Token::Type::Operator, Token::Operator::BoolEqual);
+            inline auto BoolNotEqual             = createToken(core::Token::Type::Operator, Token::Operator::BoolNotEqual);
+            inline auto BoolLessThan             = createToken(core::Token::Type::Operator, Token::Operator::BoolLessThan);
+            inline auto BoolGreaterThan          = createToken(core::Token::Type::Operator, Token::Operator::BoolGreaterThan);
+            inline auto BoolLessThanOrEqual      = createToken(core::Token::Type::Operator, Token::Operator::BoolLessThanOrEqual);
+            inline auto BoolGreaterThanOrEqual   = createToken(core::Token::Type::Operator, Token::Operator::BoolGreaterThanOrEqual);
+            inline auto BoolAnd                  = createToken(core::Token::Type::Operator, Token::Operator::BoolAnd);
+            inline auto BoolOr                   = createToken(core::Token::Type::Operator, Token::Operator::BoolOr);
+            inline auto BoolNot                  = createToken(core::Token::Type::Operator, Token::Operator::BoolNot);
+            inline auto BoolXor                  = createToken(core::Token::Type::Operator, Token::Operator::BoolXor);
+            inline auto Dollar                   = createToken(core::Token::Type::Operator, Token::Operator::Dollar);
+            inline auto Colon                    = createToken(core::Token::Type::Operator, Token::Operator::Colon);
+            inline auto ScopeResolution          = createToken(core::Token::Type::Operator, Token::Operator::ScopeResolution);
+            inline auto TernaryConditional       = createToken(core::Token::Type::Operator, Token::Operator::TernaryConditional);
+            inline auto AddressOf                = createToken(core::Token::Type::Operator, Token::Operator::AddressOf);
+            inline auto SizeOf                   = createToken(core::Token::Type::Operator, Token::Operator::SizeOf);
+            inline auto At                       = createToken(core::Token::Type::Operator, Token::Operator::At);
+            inline auto Assign                   = createToken(core::Token::Type::Operator, Token::Operator::Assign);
 
         }
 
         namespace ValueType {
 
-            constexpr auto CustomType       = createToken(core::Token::Type::ValueType, Token::ValueType::CustomType);
-            constexpr auto Padding          = createToken(core::Token::Type::ValueType, Token::ValueType::Padding);
-            constexpr auto Unsigned         = createToken(core::Token::Type::ValueType, Token::ValueType::Unsigned);
-            constexpr auto Signed           = createToken(core::Token::Type::ValueType, Token::ValueType::Signed);
-            constexpr auto FloatingPoint    = createToken(core::Token::Type::ValueType, Token::ValueType::FloatingPoint);
-            constexpr auto Auto             = createToken(core::Token::Type::ValueType, Token::ValueType::Auto);
-            constexpr auto Any              = createToken(core::Token::Type::ValueType, Token::ValueType::Any);
+            inline auto CustomType       = createToken(core::Token::Type::ValueType, Token::ValueType::CustomType);
+            inline auto Padding          = createToken(core::Token::Type::ValueType, Token::ValueType::Padding);
+            inline auto Unsigned         = createToken(core::Token::Type::ValueType, Token::ValueType::Unsigned);
+            inline auto Signed           = createToken(core::Token::Type::ValueType, Token::ValueType::Signed);
+            inline auto FloatingPoint    = createToken(core::Token::Type::ValueType, Token::ValueType::FloatingPoint);
+            inline auto Auto             = createToken(core::Token::Type::ValueType, Token::ValueType::Auto);
+            inline auto Any              = createToken(core::Token::Type::ValueType, Token::ValueType::Any);
 
-            constexpr auto Unsigned8Bit     = createToken(core::Token::Type::ValueType, Token::ValueType::Unsigned8Bit);
-            constexpr auto Unsigned16Bit    = createToken(core::Token::Type::ValueType, Token::ValueType::Unsigned16Bit);
-            constexpr auto Unsigned24Bit    = createToken(core::Token::Type::ValueType, Token::ValueType::Unsigned24Bit);
-            constexpr auto Unsigned32Bit    = createToken(core::Token::Type::ValueType, Token::ValueType::Unsigned32Bit);
-            constexpr auto Unsigned48Bit    = createToken(core::Token::Type::ValueType, Token::ValueType::Unsigned48Bit);
-            constexpr auto Unsigned64Bit    = createToken(core::Token::Type::ValueType, Token::ValueType::Unsigned64Bit);
-            constexpr auto Unsigned96Bit    = createToken(core::Token::Type::ValueType, Token::ValueType::Unsigned96Bit);
-            constexpr auto Unsigned128Bit   = createToken(core::Token::Type::ValueType, Token::ValueType::Unsigned128Bit);
+            inline auto Unsigned8Bit     = createToken(core::Token::Type::ValueType, Token::ValueType::Unsigned8Bit);
+            inline auto Unsigned16Bit    = createToken(core::Token::Type::ValueType, Token::ValueType::Unsigned16Bit);
+            inline auto Unsigned24Bit    = createToken(core::Token::Type::ValueType, Token::ValueType::Unsigned24Bit);
+            inline auto Unsigned32Bit    = createToken(core::Token::Type::ValueType, Token::ValueType::Unsigned32Bit);
+            inline auto Unsigned48Bit    = createToken(core::Token::Type::ValueType, Token::ValueType::Unsigned48Bit);
+            inline auto Unsigned64Bit    = createToken(core::Token::Type::ValueType, Token::ValueType::Unsigned64Bit);
+            inline auto Unsigned96Bit    = createToken(core::Token::Type::ValueType, Token::ValueType::Unsigned96Bit);
+            inline auto Unsigned128Bit   = createToken(core::Token::Type::ValueType, Token::ValueType::Unsigned128Bit);
 
-            constexpr auto Signed8Bit       = createToken(core::Token::Type::ValueType, Token::ValueType::Signed8Bit);
-            constexpr auto Signed16Bit      = createToken(core::Token::Type::ValueType, Token::ValueType::Signed16Bit);
-            constexpr auto Signed24Bit      = createToken(core::Token::Type::ValueType, Token::ValueType::Signed24Bit);
-            constexpr auto Signed32Bit      = createToken(core::Token::Type::ValueType, Token::ValueType::Signed32Bit);
-            constexpr auto Signed48Bit      = createToken(core::Token::Type::ValueType, Token::ValueType::Signed48Bit);
-            constexpr auto Signed64Bit      = createToken(core::Token::Type::ValueType, Token::ValueType::Signed64Bit);
-            constexpr auto Signed96Bit      = createToken(core::Token::Type::ValueType, Token::ValueType::Signed96Bit);
-            constexpr auto Signed128Bit     = createToken(core::Token::Type::ValueType, Token::ValueType::Signed128Bit);
+            inline auto Signed8Bit       = createToken(core::Token::Type::ValueType, Token::ValueType::Signed8Bit);
+            inline auto Signed16Bit      = createToken(core::Token::Type::ValueType, Token::ValueType::Signed16Bit);
+            inline auto Signed24Bit      = createToken(core::Token::Type::ValueType, Token::ValueType::Signed24Bit);
+            inline auto Signed32Bit      = createToken(core::Token::Type::ValueType, Token::ValueType::Signed32Bit);
+            inline auto Signed48Bit      = createToken(core::Token::Type::ValueType, Token::ValueType::Signed48Bit);
+            inline auto Signed64Bit      = createToken(core::Token::Type::ValueType, Token::ValueType::Signed64Bit);
+            inline auto Signed96Bit      = createToken(core::Token::Type::ValueType, Token::ValueType::Signed96Bit);
+            inline auto Signed128Bit     = createToken(core::Token::Type::ValueType, Token::ValueType::Signed128Bit);
 
-            constexpr auto Float            = createToken(core::Token::Type::ValueType, Token::ValueType::Float);
-            constexpr auto Double           = createToken(core::Token::Type::ValueType, Token::ValueType::Double);
+            inline auto Float            = createToken(core::Token::Type::ValueType, Token::ValueType::Float);
+            inline auto Double           = createToken(core::Token::Type::ValueType, Token::ValueType::Double);
 
-            constexpr auto Boolean          = createToken(core::Token::Type::ValueType, Token::ValueType::Boolean);
+            inline auto Boolean          = createToken(core::Token::Type::ValueType, Token::ValueType::Boolean);
 
-            constexpr auto Character        = createToken(core::Token::Type::ValueType, Token::ValueType::Character);
-            constexpr auto Character16      = createToken(core::Token::Type::ValueType, Token::ValueType::Character16);
-            constexpr auto String           = createToken(core::Token::Type::ValueType, Token::ValueType::String);
+            inline auto Character        = createToken(core::Token::Type::ValueType, Token::ValueType::Character);
+            inline auto Character16      = createToken(core::Token::Type::ValueType, Token::ValueType::Character16);
+            inline auto String           = createToken(core::Token::Type::ValueType, Token::ValueType::String);
 
         }
 
         namespace Separator {
 
-            constexpr auto Comma            = createToken(core::Token::Type::Separator, Token::Separator::Comma);
-            constexpr auto LeftParenthesis  = createToken(core::Token::Type::Separator, Token::Separator::LeftParenthesis);
-            constexpr auto RightParenthesis = createToken(core::Token::Type::Separator, Token::Separator::RightParenthesis);
-            constexpr auto LeftBracket      = createToken(core::Token::Type::Separator, Token::Separator::LeftBracket);
-            constexpr auto RightBracket     = createToken(core::Token::Type::Separator, Token::Separator::RightBracket);
-            constexpr auto LeftBrace        = createToken(core::Token::Type::Separator, Token::Separator::LeftBrace);
-            constexpr auto RightBrace       = createToken(core::Token::Type::Separator, Token::Separator::RightBrace);
-            constexpr auto Dot              = createToken(core::Token::Type::Separator, Token::Separator::Dot);
-            constexpr auto Semicolon        = createToken(core::Token::Type::Separator, Token::Separator::Semicolon);
-            constexpr auto EndOfProgram     = createToken(core::Token::Type::Separator, Token::Separator::EndOfProgram);
+            inline auto Comma            = createToken(core::Token::Type::Separator, Token::Separator::Comma);
+            inline auto LeftParenthesis  = createToken(core::Token::Type::Separator, Token::Separator::LeftParenthesis);
+            inline auto RightParenthesis = createToken(core::Token::Type::Separator, Token::Separator::RightParenthesis);
+            inline auto LeftBracket      = createToken(core::Token::Type::Separator, Token::Separator::LeftBracket);
+            inline auto RightBracket     = createToken(core::Token::Type::Separator, Token::Separator::RightBracket);
+            inline auto LeftBrace        = createToken(core::Token::Type::Separator, Token::Separator::LeftBrace);
+            inline auto RightBrace       = createToken(core::Token::Type::Separator, Token::Separator::RightBrace);
+            inline auto Dot              = createToken(core::Token::Type::Separator, Token::Separator::Dot);
+            inline auto Semicolon        = createToken(core::Token::Type::Separator, Token::Separator::Semicolon);
+            inline auto EndOfProgram     = createToken(core::Token::Type::Separator, Token::Separator::EndOfProgram);
 
         }
 
