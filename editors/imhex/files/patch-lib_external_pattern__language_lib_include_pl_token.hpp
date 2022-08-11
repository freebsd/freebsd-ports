--- lib/external/pattern_language/lib/include/pl/token.hpp.orig	2022-07-26 16:45:45 UTC
+++ lib/external/pattern_language/lib/include/pl/token.hpp
@@ -148,9 +148,9 @@ namespace pl {
 
         using Literal    = std::variant<char, bool, u128, i128, double, std::string, Pattern *>;
         using ValueTypes = std::variant<Keyword, Identifier, Operator, Literal, ValueType, Separator>;
+        // These changes are necessary for Clang
+        inline Token(Type type, auto value, u32 line, u32 column) : type(type), value(std::move(value)), line(line), column(column) {}
 
-        constexpr Token(Type type, auto value, u32 line, u32 column) : type(type), value(std::move(value)), line(line), column(column) {}
-
         [[nodiscard]] constexpr static inline bool isInteger(const ValueType &type) {
             return isUnsigned(type) || isSigned(type);
         }
@@ -306,128 +306,128 @@ namespace pl {
 
     namespace tkn {
 
-        constexpr inline Token createToken(const pl::Token::Type type, const pl::Token::ValueTypes &value) {
+        inline Token createToken(const pl::Token::Type type, const pl::Token::ValueTypes &value) {
             return { type, value, 0, 0 };
         }
 
         namespace Keyword {
 
-            constexpr auto If           = createToken(pl::Token::Type::Keyword, Token::Keyword::If);
-            constexpr auto Else         = createToken(pl::Token::Type::Keyword, Token::Keyword::Else);
-            constexpr auto While        = createToken(pl::Token::Type::Keyword, Token::Keyword::While);
-            constexpr auto For          = createToken(pl::Token::Type::Keyword, Token::Keyword::For);
-            constexpr auto Return       = createToken(pl::Token::Type::Keyword, Token::Keyword::Return);
-            constexpr auto Break        = createToken(pl::Token::Type::Keyword, Token::Keyword::Break);
-            constexpr auto Continue     = createToken(pl::Token::Type::Keyword, Token::Keyword::Continue);
-            constexpr auto Struct       = createToken(pl::Token::Type::Keyword, Token::Keyword::Struct);
-            constexpr auto Enum         = createToken(pl::Token::Type::Keyword, Token::Keyword::Enum);
-            constexpr auto Union        = createToken(pl::Token::Type::Keyword, Token::Keyword::Union);
-            constexpr auto Function     = createToken(pl::Token::Type::Keyword, Token::Keyword::Function);
-            constexpr auto Bitfield     = createToken(pl::Token::Type::Keyword, Token::Keyword::Bitfield);
-            constexpr auto LittleEndian = createToken(pl::Token::Type::Keyword, Token::Keyword::LittleEndian);
-            constexpr auto BigEndian    = createToken(pl::Token::Type::Keyword, Token::Keyword::BigEndian);
-            constexpr auto Parent       = createToken(pl::Token::Type::Keyword, Token::Keyword::Parent);
-            constexpr auto Namespace    = createToken(pl::Token::Type::Keyword, Token::Keyword::Namespace);
-            constexpr auto Using        = createToken(pl::Token::Type::Keyword, Token::Keyword::Using);
-            constexpr auto This         = createToken(pl::Token::Type::Keyword, Token::Keyword::This);
-            constexpr auto In           = createToken(pl::Token::Type::Keyword, Token::Keyword::In);
-            constexpr auto Out          = createToken(pl::Token::Type::Keyword, Token::Keyword::Out);
+            inline auto If           = createToken(pl::Token::Type::Keyword, Token::Keyword::If);
+            inline auto Else         = createToken(pl::Token::Type::Keyword, Token::Keyword::Else);
+            inline auto While        = createToken(pl::Token::Type::Keyword, Token::Keyword::While);
+            inline auto For          = createToken(pl::Token::Type::Keyword, Token::Keyword::For);
+            inline auto Return       = createToken(pl::Token::Type::Keyword, Token::Keyword::Return);
+            inline auto Break        = createToken(pl::Token::Type::Keyword, Token::Keyword::Break);
+            inline auto Continue     = createToken(pl::Token::Type::Keyword, Token::Keyword::Continue);
+            inline auto Struct       = createToken(pl::Token::Type::Keyword, Token::Keyword::Struct);
+            inline auto Enum         = createToken(pl::Token::Type::Keyword, Token::Keyword::Enum);
+            inline auto Union        = createToken(pl::Token::Type::Keyword, Token::Keyword::Union);
+            inline auto Function     = createToken(pl::Token::Type::Keyword, Token::Keyword::Function);
+            inline auto Bitfield     = createToken(pl::Token::Type::Keyword, Token::Keyword::Bitfield);
+            inline auto LittleEndian = createToken(pl::Token::Type::Keyword, Token::Keyword::LittleEndian);
+            inline auto BigEndian    = createToken(pl::Token::Type::Keyword, Token::Keyword::BigEndian);
+            inline auto Parent       = createToken(pl::Token::Type::Keyword, Token::Keyword::Parent);
+            inline auto Namespace    = createToken(pl::Token::Type::Keyword, Token::Keyword::Namespace);
+            inline auto Using        = createToken(pl::Token::Type::Keyword, Token::Keyword::Using);
+            inline auto This         = createToken(pl::Token::Type::Keyword, Token::Keyword::This);
+            inline auto In           = createToken(pl::Token::Type::Keyword, Token::Keyword::In);
+            inline auto Out          = createToken(pl::Token::Type::Keyword, Token::Keyword::Out);
 
         }
 
         namespace Literal {
 
-            constexpr auto Identifier   = [](const std::string &name = { }) -> Token     { return createToken(pl::Token::Type::Identifier, Token::Identifier(name)); };
-            constexpr auto Numeric      = [](const Token::Literal &value = { }) -> Token { return createToken(pl::Token::Type::Integer, value); };
-            constexpr auto String       = [](const std::string &value = { }) -> Token    { return createToken(pl::Token::Type::String, Token::Literal(value)); };
+            inline auto Identifier   = [](const std::string &name = { }) -> Token     { return createToken(pl::Token::Type::Identifier, Token::Identifier(name)); };
+            inline auto Numeric      = [](const Token::Literal &value = { }) -> Token { return createToken(pl::Token::Type::Integer, value); };
+            inline auto String       = [](const std::string &value = { }) -> Token    { return createToken(pl::Token::Type::String, Token::Literal(value)); };
 
         }
 
         namespace Operator {
 
-            constexpr auto Plus                     = createToken(pl::Token::Type::Operator, Token::Operator::Plus);
-            constexpr auto Minus                    = createToken(pl::Token::Type::Operator, Token::Operator::Minus);
-            constexpr auto Star                     = createToken(pl::Token::Type::Operator, Token::Operator::Star);
-            constexpr auto Slash                    = createToken(pl::Token::Type::Operator, Token::Operator::Slash);
-            constexpr auto Percent                  = createToken(pl::Token::Type::Operator, Token::Operator::Percent);
-            constexpr auto LeftShift                = createToken(pl::Token::Type::Operator, Token::Operator::LeftShift);
-            constexpr auto RightShift               = createToken(pl::Token::Type::Operator, Token::Operator::RightShift);
-            constexpr auto BitAnd                   = createToken(pl::Token::Type::Operator, Token::Operator::BitAnd);
-            constexpr auto BitOr                    = createToken(pl::Token::Type::Operator, Token::Operator::BitOr);
-            constexpr auto BitXor                   = createToken(pl::Token::Type::Operator, Token::Operator::BitXor);
-            constexpr auto BitNot                   = createToken(pl::Token::Type::Operator, Token::Operator::BitNot);
-            constexpr auto BoolEqual                = createToken(pl::Token::Type::Operator, Token::Operator::BoolEqual);
-            constexpr auto BoolNotEqual             = createToken(pl::Token::Type::Operator, Token::Operator::BoolNotEqual);
-            constexpr auto BoolLessThan             = createToken(pl::Token::Type::Operator, Token::Operator::BoolLessThan);
-            constexpr auto BoolGreaterThan          = createToken(pl::Token::Type::Operator, Token::Operator::BoolGreaterThan);
-            constexpr auto BoolLessThanOrEqual      = createToken(pl::Token::Type::Operator, Token::Operator::BoolLessThanOrEqual);
-            constexpr auto BoolGreaterThanOrEqual   = createToken(pl::Token::Type::Operator, Token::Operator::BoolGreaterThanOrEqual);
-            constexpr auto BoolAnd                  = createToken(pl::Token::Type::Operator, Token::Operator::BoolAnd);
-            constexpr auto BoolOr                   = createToken(pl::Token::Type::Operator, Token::Operator::BoolOr);
-            constexpr auto BoolNot                  = createToken(pl::Token::Type::Operator, Token::Operator::BoolNot);
-            constexpr auto BoolXor                  = createToken(pl::Token::Type::Operator, Token::Operator::BoolXor);
-            constexpr auto Dollar                   = createToken(pl::Token::Type::Operator, Token::Operator::Dollar);
-            constexpr auto Colon                    = createToken(pl::Token::Type::Operator, Token::Operator::Colon);
-            constexpr auto ScopeResolution          = createToken(pl::Token::Type::Operator, Token::Operator::ScopeResolution);
-            constexpr auto TernaryConditional       = createToken(pl::Token::Type::Operator, Token::Operator::TernaryConditional);
-            constexpr auto AddressOf                = createToken(pl::Token::Type::Operator, Token::Operator::AddressOf);
-            constexpr auto SizeOf                   = createToken(pl::Token::Type::Operator, Token::Operator::SizeOf);
-            constexpr auto At                       = createToken(pl::Token::Type::Operator, Token::Operator::At);
-            constexpr auto Assign                   = createToken(pl::Token::Type::Operator, Token::Operator::Assign);
+            inline auto Plus                     = createToken(pl::Token::Type::Operator, Token::Operator::Plus);
+            inline auto Minus                    = createToken(pl::Token::Type::Operator, Token::Operator::Minus);
+            inline auto Star                     = createToken(pl::Token::Type::Operator, Token::Operator::Star);
+            inline auto Slash                    = createToken(pl::Token::Type::Operator, Token::Operator::Slash);
+            inline auto Percent                  = createToken(pl::Token::Type::Operator, Token::Operator::Percent);
+            inline auto LeftShift                = createToken(pl::Token::Type::Operator, Token::Operator::LeftShift);
+            inline auto RightShift               = createToken(pl::Token::Type::Operator, Token::Operator::RightShift);
+            inline auto BitAnd                   = createToken(pl::Token::Type::Operator, Token::Operator::BitAnd);
+            inline auto BitOr                    = createToken(pl::Token::Type::Operator, Token::Operator::BitOr);
+            inline auto BitXor                   = createToken(pl::Token::Type::Operator, Token::Operator::BitXor);
+            inline auto BitNot                   = createToken(pl::Token::Type::Operator, Token::Operator::BitNot);
+            inline auto BoolEqual                = createToken(pl::Token::Type::Operator, Token::Operator::BoolEqual);
+            inline auto BoolNotEqual             = createToken(pl::Token::Type::Operator, Token::Operator::BoolNotEqual);
+            inline auto BoolLessThan             = createToken(pl::Token::Type::Operator, Token::Operator::BoolLessThan);
+            inline auto BoolGreaterThan          = createToken(pl::Token::Type::Operator, Token::Operator::BoolGreaterThan);
+            inline auto BoolLessThanOrEqual      = createToken(pl::Token::Type::Operator, Token::Operator::BoolLessThanOrEqual);
+            inline auto BoolGreaterThanOrEqual   = createToken(pl::Token::Type::Operator, Token::Operator::BoolGreaterThanOrEqual);
+            inline auto BoolAnd                  = createToken(pl::Token::Type::Operator, Token::Operator::BoolAnd);
+            inline auto BoolOr                   = createToken(pl::Token::Type::Operator, Token::Operator::BoolOr);
+            inline auto BoolNot                  = createToken(pl::Token::Type::Operator, Token::Operator::BoolNot);
+            inline auto BoolXor                  = createToken(pl::Token::Type::Operator, Token::Operator::BoolXor);
+            inline auto Dollar                   = createToken(pl::Token::Type::Operator, Token::Operator::Dollar);
+            inline auto Colon                    = createToken(pl::Token::Type::Operator, Token::Operator::Colon);
+            inline auto ScopeResolution          = createToken(pl::Token::Type::Operator, Token::Operator::ScopeResolution);
+            inline auto TernaryConditional       = createToken(pl::Token::Type::Operator, Token::Operator::TernaryConditional);
+            inline auto AddressOf                = createToken(pl::Token::Type::Operator, Token::Operator::AddressOf);
+            inline auto SizeOf                   = createToken(pl::Token::Type::Operator, Token::Operator::SizeOf);
+            inline auto At                       = createToken(pl::Token::Type::Operator, Token::Operator::At);
+            inline auto Assign                   = createToken(pl::Token::Type::Operator, Token::Operator::Assign);
 
         }
 
         namespace ValueType {
 
-            constexpr auto CustomType       = createToken(pl::Token::Type::ValueType, Token::ValueType::CustomType);
-            constexpr auto Padding          = createToken(pl::Token::Type::ValueType, Token::ValueType::Padding);
-            constexpr auto Unsigned         = createToken(pl::Token::Type::ValueType, Token::ValueType::Unsigned);
-            constexpr auto Signed           = createToken(pl::Token::Type::ValueType, Token::ValueType::Signed);
-            constexpr auto FloatingPoint    = createToken(pl::Token::Type::ValueType, Token::ValueType::FloatingPoint);
-            constexpr auto Auto             = createToken(pl::Token::Type::ValueType, Token::ValueType::Auto);
-            constexpr auto Any              = createToken(pl::Token::Type::ValueType, Token::ValueType::Any);
+            inline auto CustomType       = createToken(pl::Token::Type::ValueType, Token::ValueType::CustomType);
+            inline auto Padding          = createToken(pl::Token::Type::ValueType, Token::ValueType::Padding);
+            inline auto Unsigned         = createToken(pl::Token::Type::ValueType, Token::ValueType::Unsigned);
+            inline auto Signed           = createToken(pl::Token::Type::ValueType, Token::ValueType::Signed);
+            inline auto FloatingPoint    = createToken(pl::Token::Type::ValueType, Token::ValueType::FloatingPoint);
+            inline auto Auto             = createToken(pl::Token::Type::ValueType, Token::ValueType::Auto);
+            inline auto Any              = createToken(pl::Token::Type::ValueType, Token::ValueType::Any);
 
-            constexpr auto Unsigned8Bit     = createToken(pl::Token::Type::ValueType, Token::ValueType::Unsigned8Bit);
-            constexpr auto Unsigned16Bit    = createToken(pl::Token::Type::ValueType, Token::ValueType::Unsigned16Bit);
-            constexpr auto Unsigned24Bit    = createToken(pl::Token::Type::ValueType, Token::ValueType::Unsigned24Bit);
-            constexpr auto Unsigned32Bit    = createToken(pl::Token::Type::ValueType, Token::ValueType::Unsigned32Bit);
-            constexpr auto Unsigned48Bit    = createToken(pl::Token::Type::ValueType, Token::ValueType::Unsigned48Bit);
-            constexpr auto Unsigned64Bit    = createToken(pl::Token::Type::ValueType, Token::ValueType::Unsigned64Bit);
-            constexpr auto Unsigned96Bit    = createToken(pl::Token::Type::ValueType, Token::ValueType::Unsigned96Bit);
-            constexpr auto Unsigned128Bit   = createToken(pl::Token::Type::ValueType, Token::ValueType::Unsigned128Bit);
+            inline auto Unsigned8Bit     = createToken(pl::Token::Type::ValueType, Token::ValueType::Unsigned8Bit);
+            inline auto Unsigned16Bit    = createToken(pl::Token::Type::ValueType, Token::ValueType::Unsigned16Bit);
+            inline auto Unsigned24Bit    = createToken(pl::Token::Type::ValueType, Token::ValueType::Unsigned24Bit);
+            inline auto Unsigned32Bit    = createToken(pl::Token::Type::ValueType, Token::ValueType::Unsigned32Bit);
+            inline auto Unsigned48Bit    = createToken(pl::Token::Type::ValueType, Token::ValueType::Unsigned48Bit);
+            inline auto Unsigned64Bit    = createToken(pl::Token::Type::ValueType, Token::ValueType::Unsigned64Bit);
+            inline auto Unsigned96Bit    = createToken(pl::Token::Type::ValueType, Token::ValueType::Unsigned96Bit);
+            inline auto Unsigned128Bit   = createToken(pl::Token::Type::ValueType, Token::ValueType::Unsigned128Bit);
 
-            constexpr auto Signed8Bit       = createToken(pl::Token::Type::ValueType, Token::ValueType::Signed8Bit);
-            constexpr auto Signed16Bit      = createToken(pl::Token::Type::ValueType, Token::ValueType::Signed16Bit);
-            constexpr auto Signed24Bit      = createToken(pl::Token::Type::ValueType, Token::ValueType::Signed24Bit);
-            constexpr auto Signed32Bit      = createToken(pl::Token::Type::ValueType, Token::ValueType::Signed32Bit);
-            constexpr auto Signed48Bit      = createToken(pl::Token::Type::ValueType, Token::ValueType::Signed48Bit);
-            constexpr auto Signed64Bit      = createToken(pl::Token::Type::ValueType, Token::ValueType::Signed64Bit);
-            constexpr auto Signed96Bit      = createToken(pl::Token::Type::ValueType, Token::ValueType::Signed96Bit);
-            constexpr auto Signed128Bit     = createToken(pl::Token::Type::ValueType, Token::ValueType::Signed128Bit);
+            inline auto Signed8Bit       = createToken(pl::Token::Type::ValueType, Token::ValueType::Signed8Bit);
+            inline auto Signed16Bit      = createToken(pl::Token::Type::ValueType, Token::ValueType::Signed16Bit);
+            inline auto Signed24Bit      = createToken(pl::Token::Type::ValueType, Token::ValueType::Signed24Bit);
+            inline auto Signed32Bit      = createToken(pl::Token::Type::ValueType, Token::ValueType::Signed32Bit);
+            inline auto Signed48Bit      = createToken(pl::Token::Type::ValueType, Token::ValueType::Signed48Bit);
+            inline auto Signed64Bit      = createToken(pl::Token::Type::ValueType, Token::ValueType::Signed64Bit);
+            inline auto Signed96Bit      = createToken(pl::Token::Type::ValueType, Token::ValueType::Signed96Bit);
+            inline auto Signed128Bit     = createToken(pl::Token::Type::ValueType, Token::ValueType::Signed128Bit);
 
-            constexpr auto Float            = createToken(pl::Token::Type::ValueType, Token::ValueType::Float);
-            constexpr auto Double           = createToken(pl::Token::Type::ValueType, Token::ValueType::Double);
+            inline auto Float            = createToken(pl::Token::Type::ValueType, Token::ValueType::Float);
+            inline auto Double           = createToken(pl::Token::Type::ValueType, Token::ValueType::Double);
 
-            constexpr auto Boolean          = createToken(pl::Token::Type::ValueType, Token::ValueType::Boolean);
+            inline auto Boolean          = createToken(pl::Token::Type::ValueType, Token::ValueType::Boolean);
 
-            constexpr auto Character        = createToken(pl::Token::Type::ValueType, Token::ValueType::Character);
-            constexpr auto Character16      = createToken(pl::Token::Type::ValueType, Token::ValueType::Character16);
-            constexpr auto String           = createToken(pl::Token::Type::ValueType, Token::ValueType::String);
+            inline auto Character        = createToken(pl::Token::Type::ValueType, Token::ValueType::Character);
+            inline auto Character16      = createToken(pl::Token::Type::ValueType, Token::ValueType::Character16);
+            inline auto String           = createToken(pl::Token::Type::ValueType, Token::ValueType::String);
 
         }
 
         namespace Separator {
 
-            constexpr auto Comma            = createToken(pl::Token::Type::Separator, Token::Separator::Comma);
-            constexpr auto LeftParenthesis  = createToken(pl::Token::Type::Separator, Token::Separator::LeftParenthesis);
-            constexpr auto RightParenthesis = createToken(pl::Token::Type::Separator, Token::Separator::RightParenthesis);
-            constexpr auto LeftBracket      = createToken(pl::Token::Type::Separator, Token::Separator::LeftBracket);
-            constexpr auto RightBracket     = createToken(pl::Token::Type::Separator, Token::Separator::RightBracket);
-            constexpr auto LeftBrace        = createToken(pl::Token::Type::Separator, Token::Separator::LeftBrace);
-            constexpr auto RightBrace       = createToken(pl::Token::Type::Separator, Token::Separator::RightBrace);
-            constexpr auto Dot              = createToken(pl::Token::Type::Separator, Token::Separator::Dot);
-            constexpr auto Semicolon        = createToken(pl::Token::Type::Separator, Token::Separator::Semicolon);
-            constexpr auto EndOfProgram     = createToken(pl::Token::Type::Separator, Token::Separator::EndOfProgram);
+            inline auto Comma            = createToken(pl::Token::Type::Separator, Token::Separator::Comma);
+            inline auto LeftParenthesis  = createToken(pl::Token::Type::Separator, Token::Separator::LeftParenthesis);
+            inline auto RightParenthesis = createToken(pl::Token::Type::Separator, Token::Separator::RightParenthesis);
+            inline auto LeftBracket      = createToken(pl::Token::Type::Separator, Token::Separator::LeftBracket);
+            inline auto RightBracket     = createToken(pl::Token::Type::Separator, Token::Separator::RightBracket);
+            inline auto LeftBrace        = createToken(pl::Token::Type::Separator, Token::Separator::LeftBrace);
+            inline auto RightBrace       = createToken(pl::Token::Type::Separator, Token::Separator::RightBrace);
+            inline auto Dot              = createToken(pl::Token::Type::Separator, Token::Separator::Dot);
+            inline auto Semicolon        = createToken(pl::Token::Type::Separator, Token::Separator::Semicolon);
+            inline auto EndOfProgram     = createToken(pl::Token::Type::Separator, Token::Separator::EndOfProgram);
 
         }
 
