#[derive(PartialEq, Drop)]
struct Vector2 {
    x: felt252,
    y: felt252,
}

impl Vector2Add of Add<Vector2> {
    fn add(lhs: Vector2, rhs: Vector2) -> Vector2 {
            Vector2 { x: lhs.x + rhs.x, y: lhs.y + rhs.y }
        }
}

fn main() {
    let v = Vector2 { x: 1, y: 0 };
    let w = Vector2 { x: 0, y: 1 };
    
    assert(v + w == Vector2 { x: 1, y: 1 }, 'Should be equal.')
}

